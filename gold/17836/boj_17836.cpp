#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int r;
int c;
int time_limit;
int board[101][101];
int visited[101][101];

int bfs() {
	queue<pair<int, int> > q;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		
	}
	return (-1);
}

int main(void) {
	int ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> r >> time_limit;
	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++)
			cin >> board[row][col];
	}
	ans = bfs();
	if (ans < 0)
		cout << "Fail\n";
	else
		cout << ans << '\n';
	return (0);
}