#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int n;
    int k;
    string str;
    vector<char> stk;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (!stk.empty()) {
            while (!stk.empty() && (stk.back() < str[i]) && (stk.size() + n - i - 1 >= n - k)) {
                stk.pop_back();
            }
            if (stk.size() < n - k)
                stk.push_back(str[i]);
        }
        else
            stk.push_back(str[i]);
    }
    for (auto it = stk.begin(); it < stk.end(); it++)
        cout << *it;
    cout << '\n';
    return (0);
}
