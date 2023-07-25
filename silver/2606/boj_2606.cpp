#include <iostream>
#include <vector>

using namespace std;

int	ans;
int	num;
int	list_size;
vector<vector<int> >	adjList(101);
int	visited[101];

void	dfs(int cur) {
	if (visited[cur])
		return ;
	visited[cur] = 1;
	cout << "cur : " << cur << '\n';
	ans++;
	for (int i = 0; i < adjList[cur].size(); i++)
		dfs(adjList[cur][i]);
}

int	main(void) {
	int	start;
	int	end;
	cin >> num >> list_size;
	while (list_size--) {
		cin >> start >> end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}
	dfs(1);
	cout << ans - 1 << '\n';
	return (0);
}