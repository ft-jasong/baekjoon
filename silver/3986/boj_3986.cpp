#include <iostream>
#include <vector>
#include <string>

bool is_good_word(std::string& str) {
    std::vector<char>   stk;

    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!stk.empty()) {
            if (*it == stk.back())
                stk.pop_back();
            else
                stk.push_back(*it);
        }
        else
            stk.push_back(*it);
    }
    return (stk.empty());
}

int main(void) {
    int test_case;
    std::string str;
    int good_word_cnt;

    std::cin >> test_case;
    good_word_cnt = 0;
    while (test_case--) {
        std::cin >> str;
        if (is_good_word(str))
            good_word_cnt++;
    }
    std::cout << good_word_cnt << '\n';
    return (0);
}
