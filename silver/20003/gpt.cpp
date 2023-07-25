#include <iostream>
#include <vector>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second;
    }

    int numerator = items[0].first;
    int denominator = items[0].second;

    for (int i = 1; i < N; i++) {
        int gcd = findGCD(denominator, items[i].second);
        numerator = numerator * (items[i].second / gcd) + items[i].first * (denominator / gcd);
        denominator *= items[i].second / gcd;
        int commonGCD = findGCD(numerator, denominator);
        numerator /= commonGCD;
        denominator /= commonGCD;
    }

    cout << numerator << " " << denominator << endl;

    return 0;
}
