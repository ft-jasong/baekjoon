#include <iostream>

using namespace std;

int	main(void) {
	int	fibo[30];
	int	day;
	int	cake;
	int	n;
	int	m;

	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i < 30; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	cin >> day >> cake;
	n = fibo[day - 3];
	m = fibo[day - 2];
	for (int i = 1; i <= 100000; i++) {
		if (i * n < cake && (cake - i * n) % m == 0) {
			cout << i << '\n' << (cake - i * n) / m << '\n';
			return (0);
		}
	}
	return (0);
}