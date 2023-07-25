#include <iostream>
#include <algorithm>

int ans;
int dp[101][10001];

using namespace std;

int	main(void) {
	int	size;
	int	need;
	int	memory[101] = {0, };
	int	restart_cost[101] = {0, };

	cin >> size >> need;
	ans = 987654321;
	for (int i = 1; i <= size; i++)
		cin >> memory[i];
	for (int i = 1; i <= size; i++)
		cin >> restart_cost[i];
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j <= 10001; j++) {
			if (j >= restart_cost[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - restart_cost[i]] + memory[i]);
			else
				dp[i][j] = dp[i - 1][j];
			if (dp[i][j] >= need && j < ans)
				ans = j;
		}
	}
	cout << ans << '\n';
	return (0);
}