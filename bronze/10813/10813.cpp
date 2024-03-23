#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int M;
    int left;
    int right;

    cin >> N >> M;
    vector<int> balls;

    for (int i = 0; i < N; i++)
        balls.push_back(i + 1);
    while (M--) {
        cin >> left >> right;
        swap(balls[left - 1], balls[right - 1]);
    }
    for (auto it = balls.begin(); it < balls.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    return (0);
}
