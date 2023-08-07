#include <iostream>
#include <cmath>

using namespace std;

int	isNotPrime[1000001];

int	main(void) {
	vector<int>	primes;
	int	j;

	for (int i = 2; i < 1000001; i++) {
		if (!isNotPrime[i]) {
			j = 2;
			primes.push_back(i);
			while (i * j <= 1000000) {
				isNotPrime[i * j] = 1;
				j++;
			}
		}
	}
	for (auto it = primes.begin(); it != primes.end(); it++)
		cout << *it << '\n';
	return (0);
}