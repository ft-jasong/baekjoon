#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void) {
	int	tc;
	int	testNum;
	int	length;
	int	tmp;
	vector<int>	v;
	vector<int>	v_sorted;
	int	idx;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	v.reserve(1000);
	v_sorted.reserve(1000);
	cin >> tc;
	while (tc--) {
		cin >> testNum >> length;
		v.clear();
		v_sorted.clear();
		for (int i = 0; i < length; i++) {
			cin >> tmp;
			v.push_back(tmp);
			v_sorted.push_back(tmp);
		}
		sort(v_sorted.begin(), v_sorted.end());
		int	count = 0;
		for (int i = 0; i < length; i++) {
			
			if (v[i] == v_sorted[count])
				count++;
		}
		cout << testNum << ' ' << length - count << '\n';
	}
	return (0);
}