#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int cmd_size;
    int cmd;
    int tmp;
    stack<int> stk;

    cin >> cmd_size;
    while (cmd_size--) {
        cin >> cmd;
        switch (cmd) {
            case 1: 
                cin >> tmp;
                stk.push(tmp);
                break ;
            case 2:
                if (stk.empty()) {
                    cout << "-1\n";
                    break ;
                }
                cout << stk.top() << '\n';
                stk.pop();
                break ;
            case 3:
                cout << stk.size() << '\n';
                break ;
            case 4:
                cout << stk.empty() << '\n';
                break ;
            case 5:
                if (stk.empty()) {
                    cout << "-1\n";
                    break ;
                }
                cout << stk.top() << '\n';
                break ;
        }
    }
    return (0);
}
