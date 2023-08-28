#include <iostream>

using namespace std;

long long dp[1001][1001];

void initDp(void) {
    for (int i = 0; i <= 1000; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
}

int main(void) {
    int row, col;

    cin >> col >> row;
    initDp();
    for (int r = 1; r < row; r++) {
        for (int c = 1; c < col; c++) {
            dp[r][c] = (dp[r - 1][c] + dp[r][c - 1] + dp[r - 1][c - 1]) % 1000000007;
        }
    }
    cout << dp[row - 1][col - 1] << '\n';
    return (0);
}
