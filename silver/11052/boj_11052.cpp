#include <iostream>
#include <algorithm>

using namespace std;

int	card_price[10001];
int	dp[10001];

int main(void) {
	int	N;
	int	exp_idx;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> card_price[i];
	dp[1] = card_price[1];
	exp_idx = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = card_price[i];
		for (int j = 1; j <= (i + 1) / 2; j++)
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
	}
	cout << dp[N] << '\n';
	return (0);
}