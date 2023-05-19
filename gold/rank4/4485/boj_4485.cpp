#include <iostream>
#include <cstring>
#include <algorithm>

int map[126][126];
int dp[126][126];

using namespace std;

int main(void) {
	int	N;
	int	pnum;

	pnum = 0;
	while (++pnum) {
		cin >> N;
		if (N == 0)
			break ;
		memset(dp, 0x08, sizeof(dp));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}
		dp[1][1] = map[1][1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == 1 && j == 1) {
					cout << dp[1][1] << ' ';
					continue ;
				}
				dp[i][j] = min(map[i][j] + dp[i - 1][j], map[i][j] + dp[i][j - 1]);
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "Problem " << pnum << ": " << dp[N][N] << endl;
	}
	return (0);
}