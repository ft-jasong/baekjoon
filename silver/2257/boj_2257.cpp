#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int chem_to_val(char c) {
    if (c == 'H')
        return (1);
    if (c == 'C')
        return (12);
    if (c == 'O')
        return (16);
    return (0);
}

int solution(string& chem) {
    vector<int> val_stk;
    vector<char> chem_stk;

    for (int i = 0; i < chem.size(); i++) {
        if (isdigit(chem[i])) {
            int len = val_stk.size();
            val_stk[len - 1] = val_stk.back() * (chem[i] - '0');
        }
        else if (isalpha(chem[i])) {
            chem_stk.push_back(chem[i]);
            val_stk.push_back(chem_to_val(chem[i]));
        }
        else if (chem[i] == ')') {
            int val_sum = 0;
            while (chem_stk.back() != '(') {
                chem_stk.pop_back();
                val_sum += val_stk.back();
                val_stk.pop_back();
            }
            chem_stk.pop_back();
            chem_stk.push_back('M');
            val_stk.push_back(val_sum);
        }
        else {
            chem_stk.push_back(chem[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < val_stk.size(); i++) {
        ans += val_stk[i];
    }
    return (ans);
}

int main(void) {
    string str;

    cin >> str;
    cout << solution(str) << '\n';
    return (0);
}
