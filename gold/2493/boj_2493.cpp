#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    int inpt;
    stack<int> val_stk;
    stack<int> idx_stk;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inpt;
        while (!val_stk.empty() && val_stk.top() < inpt) {
            val_stk.pop();
            idx_stk.pop();
        }
        if (val_stk.empty())
            cout << 0 << ' ';
        else 
            cout << idx_stk.top() << ' ';
        val_stk.push(inpt);
        idx_stk.push(i + 1);
    }
    return (0);
}
