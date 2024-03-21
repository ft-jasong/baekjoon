#include <iostream>
#include <string>

void solution(void) {
    std::string msg;
    int alphabet_cnt[26] = {0, };
    int alpha_idx;

    std::cin >> msg;
    for (std::string::iterator it = msg.begin(); it != msg.end(); it++) {
        alpha_idx = *it - 'A';
        alphabet_cnt[alpha_idx]++;
        if (alphabet_cnt[alpha_idx] % 3 == 0) {
            std::string::iterator cur_iter = it;
            it++;
            if (*it != *cur_iter) {
                std::cout << "FAKE\n";
                return ;
            }
        }
    }
    std::cout << "OK\n";
}

int main(void) {
    int test_case;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> test_case;
    while (test_case--) 
        solution();
    return (0);
}
