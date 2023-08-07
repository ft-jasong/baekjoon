#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char board[26][26];
int	visited[26][26];
vector<int>	apart;
int	N;

void	bfs(int row, int col) {
	queue<pair<int, int> >	q;
	int	apt_count;
	int	x;
	int	y;
	int	dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	q.push(make_pair(row, col));
	visited[row][col] = 1;
	apt_count = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		apt_count++;
		for (int i = 0; i < 4; i++) {
			if (y + dy[i] < N && x + dx[i] < N && y + dy[i] >= 0 && x + dx[i] >= 0) {
				if ((board[y + dy[i]][x + dx[i]] > '0') && !visited[y + dy[i]][x + dx[i]]) {
					q.push(make_pair(y + dy[i], x + dx[i]));
					visited[y + dy[i]][x + dx[i]] = 1;
				}
			}
		}
	}
	apart.push_back(apt_count);
}

int	main(void) {
	cin >> N;
	for (int row = 0; row < N; row++) {
		cin >> board[row];
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (board[row][col] > '0' && !visited[row][col])
				bfs(row, col);
		}
	}
	sort(apart.begin(), apart.end());
	cout << apart.size() << '\n';
	for (int i = 0; i < apart.size(); i++)
		cout << apart[i] << '\n';
	return (0);
}