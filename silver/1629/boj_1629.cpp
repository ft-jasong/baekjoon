#include <iostream>

using namespace std;

int	getbits(int num) {
	int	bits;

	bits = 0;
	while (num) {
		num /= 2;
		bits++;
	}
	return (bits);
}

int main(void)
{
	unsigned long long	A;
	unsigned long long	B;
	unsigned long long	C;
	int					bits;
	long long			ans;

	cin >> A >> B >> C;
	bits = getbits(B);
	ans = 1;
	while (bits--) {
		ans = (ans * ans) % C;
		if (B & (1 << bits)) {
			ans *= A;
			ans %= C;
		}
	}
	cout << ans << '\n';
	return (0);
}