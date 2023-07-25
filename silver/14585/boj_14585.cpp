#include <iostream>
#include <algorithm>

using namespace std;

int board[301][301];
int	dp[301][301];
int	ans;
int N;
int M;

int main(void) {
	int x;
	int y;

	cin >> N >> M;
	while (N--) {
		int x;
		int y;

		cin >> x >> y;
		board[y][x] = M;
	}
	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			if (i + j > M)
				break ;
			if (i == 0 && j == 0)
				continue;
			else if (i > 0 && j == 0)
				dp[i][j] = dp[i - 1][j];
			else if (i == 0 && j > 0)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (board[i][j])
				dp[i][j] += board[i][j] - i - j;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return (0);
}

// 좌표는 300 300 까지 있음
// 2번째줄부터 입력받은 위치에 M만큼의 사탕이 존재함.
// 0 0 부터 출발해서 먹는데 최대한 많이 먹으면 얼마냐? 임.
// 그러면 어떻게 해야하나...
// 그냥 위쪽이랑 오른족으로 bfs 조진다음에 depth만큼 빼준만큼 더하고 max값 갱신하면 되는거아님?ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
// 애초에 위랑 오른쪽밖에 못가니까 루프도 형성안되고 