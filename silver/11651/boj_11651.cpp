#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool	compare(pair<int, int> &p1, pair<int, int> &p2) {
	if (p2.second > p1.second)
		return (true);
	else if (p2.second == p1.second) {
		if (p2.first > p1.first)
			return (true);
		return (false);
	}
	else
		return (false);
}

int main(void) {
	int	N;
	vector<pair<int, int> > v;
	int	x;
	int	y;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	v.reserve(N);
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
	return (0);
}