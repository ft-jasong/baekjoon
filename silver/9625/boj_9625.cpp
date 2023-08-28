#include <iostream>

using namespace std;

int	main(void) {
	int	fibo[46] = {0, 1, 1 };
	int	N;

	for (int i = 3; i < 46; i++)
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	cin >> N;
	cout << fibo[N - 1] << ' ' << fibo[N] << '\n';
	return (0);
}