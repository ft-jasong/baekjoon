#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	chooseA(vector<int>& tileA, int& ans) {
	ans += tileA.back();
	tileA.pop_back();
	ans += tileA.back();
	tileA.pop_back();
}

void	chooseB(vector<int>& tileB, int& ans) {
	ans += tileB.back();
	tileB.pop_back();
}

int	main(void) {
	int	N, sizeA, sizeB;
	vector<int>	tileA;
	vector<int>	tileB;
	int	inpt;
	int	ans = 0;

	cin >> N >> sizeA >> sizeB;
	tileA.resize(sizeA);
	tileB.resize(sizeB);
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
	for (int i = 0; i < N / 2 - 1; i++) {
		if (tileB.empty() || tileA.size() - 2 >= 3) {
			if ((tileA[tileA.size() - 1] + tileA[tileA.size() - 2]) > tileB.back())
				chooseA(tileA, ans);
			else
				chooseB(tileB, ans);
		}
		else
			chooseB(tileB, ans);
	}
	// 3칸 남기고 일어날 수 있는 경우의 수
	// A가 3칸 미만일 경우
	// A가 3칸 이상일 경우
	if (N % 2 == 0) {
		if (tileB.empty() || ((tileA[tileA.size() - 1] + tileA[tileA.size() - 2]) > tileB.back()))
			chooseA(tileA, ans);
		else
			chooseB(tileB, ans);
	}
	if (tileA.size() >= 3) {
		int	remain = tileA.size();
		int	sumA = tileA[remain - 1] + tileA[remain - 2] + tileA[remain - 3];
		
		if (tileB.empty())
			ans += sumA;
		else if (sumA > tileB.back() + tileA.back())
			ans += sumA;
		else
			ans += tileB.back() + tileA.back();
	}
	cout << ans << '\n';
	return (0);
}