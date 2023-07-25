#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int	adjMatrix[201][201];

int	main(void) {
	int	N;
	int	M;
	int	inpt;
	vector<int>	v_m;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> inpt;
			if (i == j)
				adjMatrix[i][j] = 1;
			else
				adjMatrix[i][j] = inpt ? inpt : 987654321;
		}
	}
	v_m.resize(M);
	for (int i = 0; i < M; i++)
		cin >> v_m[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
					adjMatrix[i][j] = 1;
					adjMatrix[j][i] = 1;
				}
			}
		}
	}
	for (int i = 0; i < M - 1; i++) {
		if (adjMatrix[v_m[i]][v_m[i + 1]] > 10000) {
			cout << "NO\n";
			return (0);
		}
	}
	cout << "YES\n";
	return (0);
}