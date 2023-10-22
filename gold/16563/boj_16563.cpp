#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int isNotPrime[5000001];
vector<int> primes;

void printDivisor(int num) {
    for (auto it = primes.begin(); it < primes.end(); it++) {
        if (num == 1)
            break ;
        if (!isNotPrime[num]) {
            cout << num;
            break ;
        }
        while (num % (*it) == 0) {
            num /= (*it);
            cout << (*it) << ' ';
        }
    }
    cout << '\n';
}

int main(void) {
    int n;
    int num;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= 5000000; i++) {
        if (!isNotPrime[i]) {
            int j = 2;
            while (i * j <= 5000000) {
                isNotPrime[i * j] = 1;
                j++;
            }
            primes.push_back(i);
        }
    }
    while (n--) {
        cin >> num;
        printDivisor(num);
    }
    return (0);
}
