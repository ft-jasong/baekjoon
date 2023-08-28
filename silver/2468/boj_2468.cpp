#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int	board[100][100];
int	visited[100][100];
int	ans;
int	n;

void bfs(int row, int col, int h) {
	queue<pair<int, int> > q;
	int	x;
	int	y;

	q.push(make_pair(row, col));
	visited[row][col] = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (x - 1 >= 0 && !visited[y][x - 1] && board[y][x - 1] > h) {
			q.push(make_pair(y, x - 1));
			visited[y][x - 1] = 1;
		}
		if (x + 1 < n && !visited[y][x + 1] && board[y][x + 1] > h) {
			q.push(make_pair(y, x + 1));
			visited[y][x + 1] = 1;
		}
		if (y - 1 >= 0 && !visited[y - 1][x] && board[y - 1][x] > h) {
			q.push(make_pair(y - 1, x));
			visited[y - 1][x] = 1;
		}
		if (y + 1 < n && !visited[y + 1][x] && board[y + 1][x] > h) {
			q.push(make_pair(y + 1, x));
			visited[y + 1][x] = 1;
		}
	}
}

int main(void) {
	int	tmp;
	int	max_h;
	int	count;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	max_h = 0;
	for (int row = 0; row < n ; row++) {
		for (int col = 0; col < n; col++) {
			cin >> tmp;
			max_h = max(max_h, tmp);
			board[row][col] = tmp;
		}
	}
	// 현재 높이를 정한다.
	// 시작점부터 끝까지 한번 bfs를 돌린다.
	// 돌린 bfs의 수가 이전 높이단위보다 크면, 값 변경.
	for (int h = 0; h <= max_h; h++) {
		bzero(visited, sizeof(visited));
		count = 0;
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (!visited[row][col] && board[row][col] > h) {
					bfs(row, col, h);
					count++;
				}
			}
		}
		ans = max(count, ans);
	}
	cout << ans << '\n';
	return (0);
}
