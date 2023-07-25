#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000][3];

int	getThreeMax(int *arr) {
	return (max(arr[0], max(arr[1], arr[2])));
}

int main(void) {
	int N;
	int	inpt[100000] = {0, };
	int	ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> inpt[i];
	dp[0][1] = inpt[0];
	ans = getThreeMax(dp[1]);
	for (int i = 2; i < N; i++) {
		dp[i][0] = getThreeMax(dp[i - 1]);
		dp[i][1] = dp[i - 1][0] + inpt[i];
		dp[i][2] = dp[i - 1][1] + inpt[i] / 2;
		ans = getThreeMax(dp[i]);
	}
	cout << ans << '\n';
	return (0);
}