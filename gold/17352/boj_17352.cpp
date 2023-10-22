#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int visited[300001];
vector<vector<int> > graph;

void dfs(int n) {
  if (visited[n])
    return;
  visited[n] = 1;
  for (int i = 0; i < graph[n].size(); i++) {
    dfs(graph[n][i]);
  }
}

int main(void) {
  int size;
  int start;
  int end;

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> size;
  graph.resize(size + 1);
  for (int i = 0; i < size - 2; i++) {
    cin >> start >> end;
    graph[start].push_back(end);
    graph[end].push_back(start);
  }
  dfs(1);
  for (int i = 1; i <= size; i++) {
    if (!visited[i]) {
      cout << 1 << ' ' << i << '\n';
      return (0);
    }
  }
  return (0);
}
