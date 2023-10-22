#include <iostream>
#include <string>

using namespace std;

string makeNewPelindrome(string& origin, string& str) {
    string newPelindrome;
    int i;

    newPelindrome += str;
    i = origin.size() % 2 == 0 ? str.size() - 1 : str.size() - 2;
    while (i >= 0) {
        newPelindrome += str[i];
        i--;
    }
    return (newPelindrome);
}

void addNumString(string& str) {
    int i = str.size() - 1;
    int carry;

    str[i]++;
    carry = 0;
    while (i >= 0) {
        str[i] += carry;
        if (str[i] > '9') {
            carry = 1;
            str[i] -= 10;
        }
        else
            carry = 0;
        i--;
        cout << i << '\n';
    }
    if (carry)
        str = "1" + str;
    cout << str << '\n';
}

int isBigger(string& a, string& b) {
    if (a.size() > b.size())
        return (-1);
    else if (a.size() < b.size())
        return (1);
    else {
        return (a.compare(b));
    }
}

int main(void) {
    string str;
    string tmp;
    string newPelindrome;
    int i;

    cin >> str;
    tmp = str.substr(0, (str.size() + 1) / 2);
    newPelindrome = makeNewPelindrome(str, tmp);
    while (isBigger(str, newPelindrome) >= 0) {
        addNumString(tmp);
        newPelindrome = makeNewPelindrome(str, tmp);
    }
    cout << newPelindrome << '\n';
    return (0);
}
