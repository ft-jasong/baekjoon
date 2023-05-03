#include <iostream>
#include <vector>

using namespace std;

unsigned int	graph[101][101];

int	main(void) {
	int	userNum, relationNum;
	int	min_cnt;
	int	ans;

	cin >> userNum >> relationNum;
	memset(graph, 10000, sizeof(graph));
	for (int i = 0; i < relationNum; i++) {
		int	u1, u2;

		cin >> u1 >> u2;
		graph[u1][u2] = 1;
		graph[u2][u1] = 1;
	}
	for (int pass = 1; pass <= userNum; pass++) {
		for (int from = 1; from <= userNum; from++) {
			for (int to = 1; to <= userNum; to++) {
				if (graph[from][to] > graph[from][pass] + graph[pass][to]) {
					graph[from][to] = graph[from][pass] + graph[pass][to];
					graph[to][from] = graph[from][pass] + graph[pass][to];
				}
			}
		}
	}
	min_cnt = 987654321;
	int	cnt;
	for (int i = 1; i <= userNum; i++) {
		cnt = 0;
		for (int j = 1; j <= userNum; j++) {
			if (graph[i][j] && i != j)
				cnt += graph[i][j];
		}
		if (cnt < min_cnt) {
			ans = i;
			min_cnt = cnt;
		}
	}
	cout << ans << endl;
	return (0);
}