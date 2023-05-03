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
	map<ull, vector<ull> > m;
	for (ull i = 0; i < cnt; i++) {
		cin >> tmp;
		if (m.find(tmp) == m.end())
			m.insert(make_pair(tmp, vector<ull>(cnt, i + 1)));
		else
			m[tmp].push_back(i + 1);
	}
	vector<pair<ull, vector<ull> > > v(m.begin(), m.end());
	v.insert(v.begin(), make_pair(0, vector<ull>(0, 0)));
	vector<ull> sum(v.size() + 1, 0);
	for (int i = 1; i < v.size(); i++)
		sum[i] = v[i].second + sum[i - 1];
	for (int i = 0; i < v.size(); i++) {
		ull least_ink = v[i].first;
		ull least_sum = least_ink * sum[i];
		ull	sum_of_ink = cnt * least_ink;

		if (sum_of_ink > total_ink) {
			if (v[i].second == 1)
				cout << v[i - 1].first << '\n';
			else
				cout << v[i].first << '\n';
			return (0);
		}
	}
	return (0);
}