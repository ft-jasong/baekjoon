#include <iostream>

using namespace std;

int board[300][300];
int dp[300][300];

int main(void) {
    int N;
    int M;
    int x;
    int y;

    cin >> N >> M;
    while (N--) {
        int x;
        int y;

        cin >> x >> y;
        board[y][x] = 1;
    }
    
}