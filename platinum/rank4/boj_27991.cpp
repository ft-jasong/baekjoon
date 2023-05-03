#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int main(void) {
	ull	cnt, total_ink, tmp;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> cnt >> total_ink;
	map<ull, ull> m;
	vector<ull> printqueue(cnt, 0);
	for (ull i = 0; i < cnt; i++) {
		cin >> tmp;
		if (m.find(tmp) == m.end())
			m.insert(make_pair(tmp, i + 1));
		printqueue[i] = tmp;
	}
	vector<pair<ull, ull> > v(m.begin(), m.end());
	v.insert(v.begin(), make_pair(0, 0));
	bool	flag = false;
	for (int i = 1; i < v.size(); i++) {
		ull curr_ink = v[i].first;
		ull	first_curr_ink_idx = v[i].second;
		ull	sum_of_ink = cnt * curr_ink;

		if (sum_of_ink > total_ink) {
			if (curr_ink * first_curr_ink_idx > total_ink) {
				if (flag) {
					cout << v[i - 1].first << '\n';
					return (0);
				}
			}
			else
				flag = true;
			ull	prev_ink = v[i - 1].first;
			ull curr_cnt = 0;
			ull prev_cnt = 0;
			ull	curr_remain = total_ink;
			ull	prev_remain = total_ink;

			for (ull j = 0; j < cnt; j++) {
				if (printqueue[j] <= curr_remain) {
					if (printqueue[j] <= curr_ink)
						curr_cnt++;
					curr_remain -= curr_ink;
				}
				if (printqueue[j] <= prev_remain) {
					if (printqueue[j] <= prev_ink)
						prev_cnt++;
					prev_remain -= prev_ink;
				}
			}
			if (curr_cnt > prev_cnt)
				cout << curr_ink << '\n';
			else
				cout << prev_ink << '\n';
			return (0);
		}
	}
	cout << v[v.size() - 1].first << '\n';
	return (0);
}