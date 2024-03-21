#include <iostream>
#include <string>

using namespace std;

char num_to_char(int num) {
    return ('0' + num);
}

string next_ant_numstr(string numstr) {
    string next_numstr = "";
    int i;

    i = 0;
    while (i < numstr.size()) {
        char c = numstr[i];
        int cnt = 0;

        while (i < numstr.size() && numstr[i] == c) {
            i++;
            cnt++;
        }
        if (cnt > 0) {
            next_numstr += c;
            next_numstr += num_to_char(cnt);
        }
        else
            break ;
    }
    return (next_numstr);
}

int main(void) {
    string numstr;
    int n;
    char mx_c;

    numstr = "1";
    cin >> n;
    while (--n) {
        numstr = next_ant_numstr(numstr);
        cout << numstr << '\n';
    }
    mx_c = numstr[0];
    for (int i = 0; i < numstr.size(); i++) {
        if (mx_c < numstr[i])
            mx_c = numstr[i];
    }
    cout << mx_c << '\n';
    return (0);
}
