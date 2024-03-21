#include <iostream>
#include <string>
#include <vector>

void solution(void) {
    std::string str;
    std::vector<char> stk;

    std::cin >> str;
    for (std::string::iterator it = str.begin(); it < str.end(); it++) {
        if (*it == ')' && !stk.empty() && stk.back() == '(')
            stk.pop_back();
        else
            stk.push_back(*it);
    }
    if (stk.empty())
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main(void) {
    int tc;

    std::cin >> tc;
    while (tc--) {
        solution();
    }
    return (0);
}
