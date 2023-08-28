#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int sticker[2][100000];
int dp[2][100000];

int main(void) {
	int test_case;
	int len;

	ios_base::sync_with_stdio(false);
	cin >> test_case;
	while (test_case--) {
		cin >> len;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++)
				cin >> sticker[i][j];
		}
		bzero(dp, sizeof(dp));
		//
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];
		for (int depth = 2; depth < len; depth++) {
			dp[0][depth] = max(dp[1][depth - 1] + sticker[0][depth],
							 max(dp[0][depth - 2], dp[1][depth - 2]) + sticker[0][depth]);
			dp[1][depth] = max(dp[0][depth - 1] + sticker[1][depth],
							 max(dp[0][depth - 2], dp[1][depth - 2]) + sticker[1][depth]);
		}
		// cout << "<<<<< dp print >>>>>\n";
		// for (int i = 0; i < 2; i ++) {
		// 	for (int j = 0; j < len; j++)
		// 		cout << dp[i][j] << ' ';
		// 	cout << '\n';
		// }
		// cout << "<<<<< dp end >>>>>\n";
		cout << max(dp[0][len - 1], dp[1][len - 1]) << '\n';
	}
	return (0);
}
