#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

bool isPPAP(std::vector<char>& stk) {
    std::size_t size;

    size = stk.size();
    if (size < 4)
        return (false);
    if (stk[size - 4] == 'P' && stk[size - 3] == 'P'
        && stk[size - 2] == 'A' && stk[size - 1] == 'P')
        return (true);
    return (false);
}

void compressPPAP(std::vector<char>& stk) {
    for (int i = 0; i < 4; i++)
        stk.pop_back();
    stk.push_back('P');
    if (isPPAP(stk))
        compressPPAP(stk);
}

int main(void) {
    std::string str;
    std::vector<char> stk;

    std::cin >> str;
    for (std::string::iterator it = str.begin(); it < str.end(); it++) {
        stk.push_back(*it);
        if (*it == 'P' && isPPAP(stk))
            compressPPAP(stk);
    }
    if (stk.size() == 1 && stk[0] == 'P')
        std::cout << "PPAP\n";
    else 
        std::cout << "NP\n";
    return (0);
}
