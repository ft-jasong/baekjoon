#include <iostream>
#include <string>

using namespace std;

bool isPelindrome(string& str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i])
            return (false);
    }
    return (true);
}

bool checkRightHalf(string& str) {
    if (isPelindrome(str))
        return (false);
    for (int i = (str.size() + 1) / 2; i < str.size(); i++) {
        if (str[i] < str[str.size() - i - 1])
            return (true);
        else if (str[i] == str[str.size() - i - 1])
            continue ;
        else
            return (false);
    }
    return (false);
}

int main(void) {
    string numStr;
    int i;
    int carry;

    cin >> numStr;
    if (checkRightHalf(numStr)) {
        for (int i = 0; i < numStr.size() / 2; i++)
            numStr[numStr.size() - i - 1] = numStr[i];
        cout << numStr << '\n';
        return (0);
    }
    i = (numStr.size() - 1) / 2;
    numStr[i]++;
    carry = 0;
    while (i >= 0) {
        numStr[i] = numStr[i] + carry;
        if (numStr[i] > '9') {
            numStr[i] -= 10;
            carry = 1;
        }
        else
            carry = 0;
        numStr[numStr.size() - i - 1] = numStr[i];
        i--;
    }
    if (carry) {
        cout << 1;
        for (int i = 0; i < numStr.size() - 1; i++)
            cout << 0;
        cout << 1 << '\n';
    }
    else
        cout << numStr << '\n';
    return (0);
}
