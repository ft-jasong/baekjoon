#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int	N;
	int	p;
	int	q;
	int	r;

	cin >> N;
	if (N <= 4)  {
		cout << 4 << '\n';
		return (0);
	}
	p = sqrt(N);
	q = N / p;
	r = N % p;
	q = r > 0 ? q + 1 : q;
	cout << (p + q - 2) * 2 << '\n';
	return (0);
}