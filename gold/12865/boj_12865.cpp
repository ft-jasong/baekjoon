#include <iostream>
#include <algorithm>

int	dp[101][100001];
int	weights[101];
int	values[101];

using namespace std;

int main(void) {
	int	size;
	int	maxWeight;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> size >> maxWeight;
	for (int i = 1; i <= size; i++)
		cin >> weights[i] >> values[i];
	for (int n = 1; n <= size; n++) {
		for (int w = 1; w <= maxWeight; w++) {
			if (weights[n] <= w)
				dp[n][w] = max(values[n] + dp[n - 1][w - weights[n]], dp[n - 1][w]);
			else
				dp[n][w] = dp[n - 1][w];
		}
	}
	cout << dp[size][maxWeight] << '\n';
	return (0);
}