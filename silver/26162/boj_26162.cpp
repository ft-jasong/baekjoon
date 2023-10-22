#include <iostream>

using namespace std;

bool isPrime(int num) {
    int i;

    i = 2;
    while (i * i <= num) {
        if (num % i == 0)
            return (false);
        i++;
    }
    return (true);
}

void validation(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            cout << "Yes\n";
            return ;
         }
    }
    cout << "No\n";
}

int main(void) {
    int tc;
    int num;

    cin >> tc;
    while (tc--) {
        cin >> num;
        validation(num);
    }
    return (0);
}
