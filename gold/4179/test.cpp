#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int		maxRow;
int		maxCol;
char	board[1001][1001];
int		visited[1001][1001];
int		fireBoard[1001][1001];
int		startRow;
int		startCol;
int		fireCnt = 1;

typedef pair<int, int> Pos;

void spreadFire(int r, int c) {
	if (r - 1 >= 0 && !fireBoard[r - 1][c] && board[r - 1][c] != '#')
		fireBoard[r - 1][c] = fireCnt + 1;
	if (r + 1 <= maxRow && !fireBoard[r + 1][c] && board[r + 1][c] != '#')
		fireBoard[r + 1][c] = fireCnt + 1;
	if (c - 1 >= 0 && !fireBoard[r][c - 1] && board[r][c - 1] != '#')
		fireBoard[r][c - 1] = fireCnt + 1;
	if (c + 1 < maxCol && !fireBoard[r][c + 1] && board[r][c + 1] != '#')
		fireBoard[r][c + 1] = fireCnt + 1;
}

void updateFireboard(void) {
	for (int r = 0; r < maxRow; r++) {
		for (int c = 0; c < maxCol; c++) {
			if (fireBoard[r][c] == fireCnt) {
				spreadFire(r, c);
			}
		}
	}
	fireCnt++;
}

bool isBoardBound(int r, int c) {
	return (r >= 0 && r < maxRow && c >= 0 && c < maxCol);
}

int bfs() {
	int move;
	int curRow;
	int curCol;
	queue<pair<Pos, int> > q;
	Pos pos;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	move = 1;
	pos = make_pair(startRow, startCol);
	q.push(make_pair(pos, move));
	visited[startRow][startCol] = 1;
	while (!q.empty()) {
		if (q.front().second > move)
			updateFireboard();
		curRow = q.front().first.first;
		curCol = q.front().first.second;
		move = q.front().second;
		q.pop();
		if (fireBoard[curRow][curCol])
			continue;
		if (curRow == 0 || curRow == maxRow - 1 ||
			curCol == 0 || curCol == maxCol - 1 && !fireBoard[curRow][curCol]) {
			return (move); 
		}
		for (int i = 0; i < 4; i++) {
			if (!visited[curRow + dy[i]][curCol + dx[i]] &&
				isBoardBound(curRow + dy[i], curCol + dx[i]) &&
				!fireBoard[curRow + dy[i]][curCol + dx[i]] &&
				board[curRow + dy[i]][curCol + dx[i]] != '#') {
				visited[curRow + dy[i]][curCol + dx[i]] = 1;
				pos = make_pair(curRow + dy[i], curCol + dx[i]);
				q.push(make_pair(pos, move + 1));
			}
		}
	}
	return (-1);
}

void fillBoard(void) {
	for (int r = 0; r < maxRow; r++) {
		for (int c = 0; c < maxCol; c++) {
			cin >> board[r][c];
			if (board[r][c] == 'F')
				fireBoard[r][c] = 1;
			else if (board[r][c] == 'J') {
				startRow = r;
				startCol = c;
			}
		}
	}
}

int main(void) {
	int ans;

	cin >> maxRow >> maxCol;
	fillBoard();
	ans = bfs();
	if (ans > 0)
		cout << ans << '\n';
	else
		cout << "IMPOSSIBLE\n";
	return (0);
}

