#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void) {
	int	tc;
	vector<int>	woods;
	int	woodSize;
	int	tmp;
	int	ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--) {
		ans = 0;
		woods.clear();
		cin >> woodSize;
		woods.resize(woodSize);
		for (int i = 0; i < woodSize; i++)
			cin >> woods[i];
		sort(woods.begin(), woods.end());
		for (int i = 0; i < woodSize - 2; i++)
			ans = max(ans, woods[i + 2] - woods[i]);
		cout << ans << '\n';
	}
	return (0);
}