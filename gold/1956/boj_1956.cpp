#include <iostream>
#include <cstring>

using namespace std;

int	adjMatrix[401][401];

int main(void) {
	int	V;
	int	E;
	int	start;
	int	end;
	int	weight;
	int	ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	memset(adjMatrix, 0x0f, sizeof(adjMatrix));
	for (int e_idx = 0; e_idx < E; e_idx++) {
		cin >> start >> end >> weight;
		adjMatrix[start][end] = weight;
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
			}
		}
	}
	ans = 252645136;
	for (int i = 1; i <= V; i++) {
		if (ans > adjMatrix[i][i])
			ans = adjMatrix[i][i];
	}
	cout << ((ans >= 252645135) ? -1 : ans) << '\n';
	return (0);
}