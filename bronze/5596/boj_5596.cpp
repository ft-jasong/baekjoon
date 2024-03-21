// BOJ 5596 시험 점수

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s = 0, t = 0;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        s += x;
    }
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        t += x;
    }
    cout << max(s, t);
    return 0;
}