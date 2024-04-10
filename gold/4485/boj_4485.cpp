#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 987654321
using namespace std;

vector<pair<int, int> > graph[126];
int d[126];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_num;
    int map_size;
    int tmp;

    test_num = 0;
    while (++test_num) {
        cin >> map_size;
        if (!map_size)
            return (0);
        for (int i = 1; i <= map_size; i++)
            d[i] = INF;
        for (int i = 1; i <= map_size; i++) {
            for (int j = 1; j <= map_size; j++) {
                cin >> tmp;
            }
        }
    }
}
