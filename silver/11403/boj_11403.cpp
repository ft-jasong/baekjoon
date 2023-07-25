#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int main(void) {
	int	N;
	int	graph[100][100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = 987654321;
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			int	tmp;

			cin >> tmp;
			if (tmp > 0)
				graph[row][col] = tmp;
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] > (graph[i][k] + graph[k][j]))
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (graph[row][col] < 987654321)
				cout << 1 << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
	return (0);
}