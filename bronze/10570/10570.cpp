#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;

	cin >> tc;
	while (tc--) {
		int nums[1001] = {0, };
		int nc;
		int num;

		cin >> nc;
		while (nc--) {
			cin >> num;
			nums[num]++;
		}
		int mx = 0;
		int ans = 1;
		for (int i = 1; i <= 1000; i++) {
			if (nums[i] > mx) {
				mx = nums[i];
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return (0);
}
