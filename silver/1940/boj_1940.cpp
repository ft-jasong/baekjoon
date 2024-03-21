#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    int m;
    int values[100001] = { 0, };
    int inpt;
    int ans;

    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> inpt;
        values[inpt]++;
    }
    if (m > 200000) {
        cout << "0\n";
        return (0);
    }
    ans = 0;
    for (int i = 1; i <= m / 2 ; i++) {
        if (i > 100000 || m - i > 100000)
            continue ;
        if (i == m - i)
            ans += values[i] / 2;
        else
            ans += min(values[i], values[m - i]);
    }
    cout << ans << '\n';
    return (0);
}
