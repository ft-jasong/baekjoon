#include <iostream>

using namespace std;

void rotate_basket(int origin[], int begin, int end, int mid) {
    int i;
    int tmp_idx;
    int origin_idx;
    int tmp[101];

    for (int i = 0; i <= 100; i++) {
        tmp[i] = origin[i];
    }
    origin_idx = begin;
    tmp_idx = mid;
    while (tmp_idx <= end) {
        origin[origin_idx] = tmp[tmp_idx];
        origin_idx++;
        tmp_idx++;
    }
    tmp_idx = begin;
    while (tmp_idx < mid) {
        origin[origin_idx] = tmp[tmp_idx];
        origin_idx++;
        tmp_idx++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int i, j, k;
    int baskets[101] = {0, };

    cin >> n >> m;
    for (int i = 0; i <= 100; i++)
        baskets[i] = i;
    while (m--) {
        cin >> i >> j >> k;
        rotate_basket(baskets, i, j, k);
    }
    for (int i = 1; i <= n; i++)
        cout << baskets[i] << ' ';
    cout << '\n';
    return (0);
}
