#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF 987654321

int V;
int E;
int K;

vector<pair<int, int> > graph[20001];
int d[20001];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            int nextDistance = distance + graph[current][i].second;
            int next = graph[current][i].first;
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int s;
    int e;
    int w;

    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++)
        d[i] = INF;
    for (int i = 1; i <= E; i++) {
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
    return (0);
}
