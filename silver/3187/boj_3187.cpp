#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int		row_size;
int		col_size;
char	map[250][250];
int		visited[250][250];
int		sheep;
int		wolf;

void	bfs(int row, int col) {
	vector<pair<int, int> >	q;
	int	sheep_cnt;
	int	wolf_cnt;
	int	cr;
	int	cc;

	sheep_cnt = 0;
	wolf_cnt = 0;
	visited[row][col] = 1;
	q.push_back(make_pair(row, col));
	while (!q.empty()) {
		cr = q.front().first;
		cc = q.front().second;
		q.erase(q.begin());
		if (map[cr][cc] == 'k')
			sheep_cnt++;
		if (map[cr][cc] == 'v')
			wolf_cnt++;
		if (cr - 1 >= 0 && !visited[cr - 1][cc]) {
			q.push_back(make_pair(cr - 1, cc));
			visited[cr - 1][cc] = 1;
		}
		if (cr + 1 < row_size && !visited[cr + 1][cc]) {
			q.push_back(make_pair(cr + 1, cc));
			visited[cr + 1][cc] = 1;
		}
		if (cc - 1 >= 0 && !visited[cr][cc - 1]) {
			q.push_back(make_pair(cr, cc - 1));
			visited[cr][cc - 1] = 1;
		}
		if (cc + 1 < col_size && !visited[cr][cc + 1]) {
			q.push_back(make_pair(cr, cc + 1));
			visited[cr][cc + 1] = 1;
		}
	}
	if (sheep_cnt > wolf_cnt)
		sheep += sheep_cnt;
	else
		wolf += wolf_cnt;
}


int main(void) {
	cin >> row_size >> col_size;
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			cin >> map[r][c];
			if (map[r][c] == '#')
				visited[r][c] = 1;
		}
	}
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			if (!visited[r][c])
				bfs(r, c);
		}
	}
	cout << sheep << ' ' << wolf << '\n';
	return (0);
}