#include <iostream>

using namespace std;

int main(void) {
    int tc;
    int a;
    int b;
    int tmp;

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        tmp = a;
        while (--b) {
            tmp *= a;
            tmp %= 10;
        }
        if (tmp % 10 == 0)
            cout << "10\n";
        else
            cout << tmp << '\n';
    }
    return (0);
}
