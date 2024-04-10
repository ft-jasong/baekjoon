#include <iostream>
#include <cstring>

using namespace std;

int	map[50][50];
int	visited[50][50];
int	col_size;
int	row_size;
int	loc_size;
int	ans;

void	dfs(int x, int y) {
	if (x < 0 || x >= col_size || y < 0 || y >= row_size)
		return ;
	if (visited[y][x])
		return ;
	if (!map[y][x])
		return ;
	visited[y][x] = 1;
	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x + 1, y);
}

int	main(void) {
	int	test_case;
	int	x;
	int	y;

	cin >> test_case;
	while (test_case--) {
		bzero(map, sizeof(map));
		bzero(visited, sizeof(visited));
		ans = 0;
		cin >> col_size >> row_size >> loc_size;
		while (loc_size--) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < col_size; i++) { // x
			for (int j = 0; j < row_size; j++) { // y
				if (map[j][i] && !visited[j][i]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
