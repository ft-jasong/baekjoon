#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int	N;
	int	P;
	vector<vector<int> > v;
	int	line_num;
	int	pratt_num;
	int	ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P;
	v.resize(N);
	ans = 0;
	while (N--) {
		cin >> line_num >> pratt_num;
		while (!v[line_num].empty() && v[line_num].back() > pratt_num) {
			v[line_num].pop_back();
			ans++;
		}
		if (v[line_num].empty() || v[line_num].back() < pratt_num) {
			v[line_num].push_back(pratt_num);
			ans++;
		}
	}
	cout << ans << '\n';
	return (0);
}