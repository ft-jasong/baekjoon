#include <iostream>
#include <cstring>

long long adj[101][101];

using namespace std;

int	main(void) {
	int	n;
	int	m;
	int	s;
	int	d;
	int	l;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(adj, 0x0f, sizeof(adj));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> l;
		if (adj[s][d] > l)
			adj[s][d] = l;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] > 1000000000)
				cout << 0 << ' ';
			else
				cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	return (0);
}