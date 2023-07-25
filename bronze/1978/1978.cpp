#include <iostream>
#include <cmath>

using namespace std;

bool	isPrime(int n) {
	long long	n_sqrt = sqrt(n);

	if (n == 1)
		return false;
	for (int i = 2; i <= n_sqrt; i++) {
		if (n % i == 0)
			return (false);
	}
	return (true);
}

int	main(void) {
	int	N, input;
	int	ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (isPrime(input))
			ans++;
	}
	cout << ans << endl;
}