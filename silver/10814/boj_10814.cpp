#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

template <typename T>
bool	compare(T p1, T p2) {
	return (p1.first < p2.first);
}

int	main(void) {
	vector<pair<int, string> > v;
	int	N;
	int	age;
	string	name;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	v.reserve(N);
	while (N--) {
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}
	stable_sort(v.begin(), v.end(), compare<pair<int, string> >);
	for (auto it = v.begin(); it != v.end(); it++)
		cout << it->first << ' ' << it->second << '\n';
	return (0);
}