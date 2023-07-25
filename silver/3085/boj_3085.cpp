#include <iostream>
#include <algorithm>
#include <string.h>

char candy[50][50];
char tmp[50][50];

int	max_len;

using namespace std;

void	update_max_len(int N) {
	char	prev_alpha;
	int		cur_len;

	cur_len = 0;
	for (int i = 0; i < N; i++) {
		prev_alpha = tmp[i][0];
		for (int j = 0; j < N; j++) {
			if (prev_alpha == tmp[i][j])
				cur_len++;
			else {
				cur_len = 1;
				prev_alpha = tmp[i][j];
			}
			max_len = max(cur_len, max_len);
		}
		cur_len = 0;
	}
	for (int i = 0; i < N; i++) {
		prev_alpha = tmp[0][i];
		for (int j = 0; j < N; j++) {
			if (prev_alpha == tmp[j][i])
				cur_len++;
			else {
				cur_len = 1;
				prev_alpha = tmp[j][i];
			}
			max_len = max(cur_len, max_len);
		}
		cur_len = 0;
	}
}

int main(void) {
	int	N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}
	memcpy(tmp, candy, sizeof(candy));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(tmp[i][j], tmp[i][j + 1]);
			update_max_len(N);
			memcpy(tmp, candy, sizeof(candy));
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			swap(tmp[i][j], tmp[i + 1][j]);
			update_max_len(N);
			memcpy(tmp, candy, sizeof(candy));
		}
	}
	cout << max_len << '\n';
	return (0);
}