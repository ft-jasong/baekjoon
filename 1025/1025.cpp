#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool	isSquare(int num) {
	int	root = sqrt(num);

	if (root * root == num)
		return (true);
	return (false);
}

int	makeNum(vector<string>& mat, int x_pos, int y_pos, int row_d, int col_d, int row_len, int col_len) {
	int	ret = 0;
	int	tmp = 0;

	if (!row_d && !col_d)
		return ((int)mat[y_pos][x_pos]);
	while (y_pos >= 0 && y_pos < col_len && x_pos >= 0 && x_pos < row_len) {
		tmp = tmp * 10 + (int)mat[y_pos][x_pos];
		if (isSquare(tmp))
			ret = tmp;
		y_pos += col_d;
		x_pos += row_d;
	}
	return (ret);
}

int	main(void) {
	int	n, m;
	vector<string>			mat;
	int						ans = -1;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string	row = "";

		cin >> row;
		for (int j = 0; j < m; j++)
			row[j] -= '0';
		mat.push_back(row);
		row.clear();
	}
	// 시작지점, 행 공차, 열 공차
	for (int y_start = 0; y_start < n; y_start++) {
		for (int x_start = 0; x_start < m; x_start++) {
			for (int col_d = -n + 1; col_d < n; col_d++) {
				for (int row_d = -m + 1; row_d < m; row_d++) {
					int	y_pos = y_start;
					int	x_pos = x_start;
					int	tmp = 0;

					if (!col_d && !row_d) {
						if (isSquare(mat[y_pos][x_pos]) && mat[y_pos][x_pos] > ans)
							ans = mat[y_pos][x_pos];
						continue ;
					}
					while (y_pos >= 0 && y_pos < n && x_pos >= 0 && x_pos < m) {
						tmp = tmp * 10 + (int)mat[y_pos][x_pos];
						if (isSquare(tmp) && tmp > ans)
							ans = tmp;
						y_pos += col_d;
						x_pos += row_d;
					}
				}
			}
		}
	}
	cout << ans << endl;
}