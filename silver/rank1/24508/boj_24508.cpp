#include <iostream>

using namespace std;

long long	_sum;
int			bag[100001];

int	main(void) {
	int	N, K, T;
	int	num;
	long long	least;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> T;
	for (int i = 0; i < N; i++) {
		cin >> num;
		_sum += num;
		bag[num % K]++;
	}
	cout << _sum << '\n';
	cout << K << '\n';
	if (_sum % K != 0) {
		cout << "NO" << '\n';
		return (0);
	}
	_sum = 0;
	bag[0] = 0;
	for (int i = 1; i <= K / 2; i++) {
		if (K % 2 == 0 && i == K / 2)
			_sum += bag[K - i] * i / 2;
		else
			_sum += bag[K - i] * i;
	}
	cout << _sum << '\n';
	if (_sum > T)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';
	return (0);
}
