#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int isNotPrime[1000001];
vector<int> primes;

bool isTwoPrimeSum(int n, pair<int, int>& primePair) {
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] > n)
            break ;
        if (!isNotPrime[n - primes[i]]) {
            primePair = make_pair(primes[i], n - primes[i]);
            return (true);
        }
    }
    return (false);
}

int main(void) {
    int N;
    pair<int, int> p1;
    pair<int, int> p2;

    cin >> N;
    if (N < 8) {
        cout << "-1\n";
        return (0);
    }
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    primes.reserve(80000);
    primes.push_back(2);
    for (int i = 3; i < 1000001; i += 2) {
        if (i - 1 > 2)
            isNotPrime[i - 1] = 1;
        if (!isNotPrime[i]) {
            primes.push_back(i);
            int j = 2;

            while (j * i < 1000001) {
                isNotPrime[j * i] = 1;
                j++;
            }
        }
    }
    for (int i = 4; i <= N / 2; i++) {
        if (isTwoPrimeSum(i, p1) && isTwoPrimeSum(N - i, p2)) {
            cout << p1.first <<  ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << '\n';
            return (0);
        }
    }
    cout << "-1\n";
    return (0);
}
