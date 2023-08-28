#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int	board[251][251];
int	visited[251][251];
int	ans;
int	y_size;
int	x_size;

void	bfs(int row, int col) {
	int	x;
	int	y;
	int	dx[8] = {-1, 0, 1, 0, 1, 1 ,-1, -1};
	int	dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
	queue<pair<int, int> > q;

	ans++;
	q.push(make_pair(row, col));
	visited[row][col] = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			if ((x + dx[i] >= 0) && (y + dy[i] >= 0) && (x + dx[i] < x_size) && (y + dy[i] < y_size)) {
				if (!visited[y + dy[i]][x + dx[i]] && board[y + dy[i]][x + dx[i]]) {
					q.push(make_pair(y + dy[i], x + dx[i]));
					visited[y + dy[i]][x + dx[i]] = 1;
				}
			}
		}
	}
}

int main(void) {
	cin >> y_size >> x_size;
	for (int row = 0; row < y_size; row++) {
		for (int col = 0; col < x_size; col++) {
			cin >> board[row][col];
		}
	}
	for (int row = 0; row < y_size; row++) {
		for (int col = 0; col < x_size; col++) {
			if (!visited[row][col] && board[row][col])
				bfs(row, col);
		}
	}
	cout << ans << '\n';
	return (0);
}