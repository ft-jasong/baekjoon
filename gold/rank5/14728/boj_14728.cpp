#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int	num;
int	maxTime;

int	main(void) {
	int	dp[101][10001];
	int	timeCost[101];
	int	score[10001];

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> num >> maxTime;
	for (int i = 1; i <= num; i++)
		cin >> timeCost[i] >> score[i];
	bzero(dp, sizeof(dp));
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= maxTime; j++) {
			if (j >= timeCost[i])
				dp[i][j] = max(score[i] + dp[i - 1][j - timeCost[i]], dp[i - 1][j]);	
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[num][maxTime] << '\n';
	return (0);
}