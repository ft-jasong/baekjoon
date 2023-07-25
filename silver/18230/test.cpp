#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void) {
	int	N, sizeA, sizeB;
	int	idxA, idxB;
	int	ans;
	int	minA;
	vector<int>	tileA;
	vector<int>	tileB;

	cin >> N >> sizeA >> sizeB;
	idxA = sizeA - 1;
	idxB = sizeB - 1;
	tileA.resize(sizeA);
	tileB.resize(sizeB);
	ans = 0;
	if (N & 0x01)
		minA = 3;
	else
		minA = 0;
	for (int i = 0; i < sizeA; i++)
		cin >> tileA[i];
	for (int i = 0; i < sizeB; i++)
		cin >> tileB[i];
	sort(tileA.begin(), tileA.end());
	sort(tileB.begin(), tileB.end());
	if (N == 1) {
		cout << tileA.back() << '\n';
		return (0);
	}
	while (N > 3) {
		if (idxB + 1 > 0) {
			if (idxA - 1 >= minA && (tileA[idxA] + tileA[idxA - 1]) > tileB[idxB]) {
				ans += tileA[idxA] + tileA[idxA - 1];
				idxA -= 2;
			}
			else {
				ans += tileB[idxB];
				--idxB;
			}
		}
		else {
			ans += tileA[idxA] + tileA[idxA - 1];
			idxA -= 2;
		}
		N -= 2;
	}
	if (N == 3) {
		if (idxA >= 2) {
			if (idxB >= 0) {
				if (tileA[idxA - 1] + tileA[idxA - 2] < tileB[idxB])
					ans += tileB[idxB] + tileA[idxA];
				else
					ans += tileA[idxA] + tileA[idxA - 1] + tileA[idxA - 2];
			}
			else
				ans += tileA[idxA] + tileA[idxA - 1] + tileA[idxA - 2];
		}
		else
			ans += tileB[idxB] + tileA[idxA];
	}
	else {
		if (idxA < 1)
			ans += tileB[idxB];
		else if (idxB < 0)
			ans += tileA[idxA] + tileA[idxA - 1];
		else {
			if (tileB[idxB] > tileA[idxA] + tileA[idxA - 1])
				ans += tileB[idxB];
			else
				ans += tileA[idxA] + tileA[idxA - 1];
		}
	}
	cout << ans << endl;
}