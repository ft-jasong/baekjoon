#include <iostream>
#include <algorithm>

using namespace std;

char	board[51][51];

int main(void) {
	int	N;
	int	cur;
	int	ans;

	cin >> N;
	ans = 0;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	for (int i = 0; i < N; i++) {
		cur = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue ;
			if (board[i][j] == 'Y') {
				cur++;
				continue ;
			}
			else {
				for (int k = 0; k < N; k++) {
					if ((board[i][k] == 'Y') && (board[j][k] == 'Y')) {
						cur++;
						break ;
					}
				}
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return (0);
}