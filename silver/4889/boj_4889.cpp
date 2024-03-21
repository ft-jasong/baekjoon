#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printAns(int tc, int ans) {
    cout << tc << ". " << ans << '\n';
}

int main(void) {
    string str;
    vector<char> v;
    int tc;
    int ans;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    tc = 0;
    while (++tc) {
        ans = 0;
        cin >> str;
        if (str.find('-') != string::npos)
            return (0);
        for (auto it = str.begin(); it < str.end(); it++) {
            if (!v.empty() && *it == '}' && v.back() == '{')
                v.pop_back();
            else
                v.push_back(*it);
        }
        for (int i = 0; i < v.size(); i += 2) {
            if (v[i] == v[i + 1])
                ans++;
            else
                ans += 2;
        }
        printAns(tc, ans);
        v.clear();
    }
    return (0);
}
