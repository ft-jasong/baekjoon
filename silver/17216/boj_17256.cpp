#include <iostream>
#include <algorithm>

using namespace std;

int	arr[1000];
int	dp[1000];

int	main(void) {
	int	size;
	int	ans;

	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	dp[0] = arr[0];
	ans = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ans = max(dp[i], ans);
	}
	cout << '\n'<< ans << '\n';
}