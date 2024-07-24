#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int not_prime[110] = {0, };
	vector<int> primes;
	int num;

	for (int i = 2; i < 105; i++) {
		if (!not_prime[i]) {
			primes.push_back(i);
			for (int j = 2; i * j < 105; j++)
				not_prime[i * j] = 1;
		}
	}
	cin >> num;
	for (int i = 0; i < primes.size() - 1; i++) {
		if (primes[i] * primes[i + 1] > num) {
			cout << primes[i] * primes[i + 1] << '\n';
			return (0);
		}
	}
	return (0);
}
