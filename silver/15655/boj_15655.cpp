#include <iostream>
#include <vector>
#include <algorithm>

int ans_arr[10001];
int is_selected[10001];
int N;
int M;

using namespace std;

void backtrack(vector<int>& v, int depth, int start_idx) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ans_arr[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = start_idx; i < v.size(); i++) {
            if (!is_selected[i]) {
                is_selected[i] = 1;
                ans_arr[depth] = v[i];
                backtrack(v, depth + 1, i + 1);
                is_selected[i] = 0;
            }
        }
    }
}

int main(void) {
    vector<int> v;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    backtrack(v, 0, 0);
    return (0);
}