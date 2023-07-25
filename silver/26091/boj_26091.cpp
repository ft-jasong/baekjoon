#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void) {
	vector<int> v;
	int	N;
	int	M;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	v.reserve(N);
	while (N--) {
		int inpt;

		cin >> inpt;
		v.push_back(inpt);
	}
	sort(v.begin(), v.end());
	int	start;
	int	end;
	int	ans;
	end = v.size() - 1;
	start = 0;
	ans = 0;
	while (start < end) {
		if (v[end] + v[start] > M) {
			ans++;
			end--;
		}
		start++;
	}
	cout << ans << '\n';
	return (0);
}