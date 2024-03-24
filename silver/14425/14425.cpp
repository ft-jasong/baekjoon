#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    int N;
    int M;
    unordered_map<string, bool> hash;
    string tmp;
    int ans;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    while (N--) {
        cin >> tmp;
        hash[tmp] = true;
    }
    ans = 0;
    while (M--) {
        cin >> tmp;
        if (hash.find(tmp) != hash.end())
            ans++;
    }
    cout << ans << '\n';
    return (0);
} 
