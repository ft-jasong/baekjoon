#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    string str;
    vector<string> v;
    int len;
    int ans;

    cin >> len;
    v.reserve(len);
    for (int i = 0; i < len; i++) {
        cin >> str;
        v.push_back(str);
    }
    for (ans = 0; ans < str.length(); ans++) {
        unordered_map<string, string> mp;

        mp.clear();
        for (vector<string>::iterator it = v.begin(); it < v.end(); it++) {
            string tmp;

            tmp = (*it).substr((*it).size() - ans);
            mp.insert(make_pair(tmp, tmp));
        }
        if (mp.size() == v.size())
            break ;
    }
    cout << ans << '\n';
    return (0);
}
