#include <iostream>
#include <stack>

using namespace std;

int calAns(stack<int>& size_stk, stack<char> alpha_stk) {
    int ans;

    ans = 0;
    while (!alpha_stk.empty()) {
        if (alpha_stk.top() == 'a') {
            ans += size_stk.top();
            size_stk.pop();
        }
        else
            ans += 1;
        alpha_stk.pop();
    }
    return (ans);
}

int main(void) {
    string str;
    stack<int> size_stk;
    stack<char> alpha_stk;

    cin >> str;
    for (auto it = str.begin(); it < str.end(); it++) {
        if (*it != ')') {
            alpha_stk.push(*it);
        }
        else {
            int cur_len = 0;
            while (!alpha_stk.empty() && alpha_stk.top() != '(') {
                if (alpha_stk.top() == 'a') {
                    cur_len += size_stk.top();
                    size_stk.pop();
                    alpha_stk.pop();
                }
                else {
                    alpha_stk.pop();
                    cur_len += 1;
                }
            }
            alpha_stk.pop();
            cur_len *= (alpha_stk.top() - '0');
            alpha_stk.pop();
            alpha_stk.push('a');
            size_stk.push(cur_len);
        }
    }
    cout << calAns(size_stk, alpha_stk) << '\n';
    return (0);
}
