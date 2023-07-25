#include <iostream>
#include <deque>
#include <iomanip>
#include <cmath>

typedef unsigned long long ull;

using namespace std;

ull	getGCD(ull a, ull b) {
	ull	r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

ull sqrt_ull(ull x) {
	ull	low = 0;
	ull	high = 1073741824ULL;
	ull mid;

	while (low <= high) {
		mid  = (low + high) / 2;
		if (mid * mid > x)
			high = mid - 1;
		else if (mid * mid < x)
			low = mid + 1;
		else
			return (mid);
	}
	return (high);
}

void	printAnswer(ull count, ull range) {
	ull	gcd;

	if (count == 0) {
		cout << 0 << '\n';
		return ;
	}
	gcd = getGCD(range, count);
	cout << count / gcd << '/' << range / gcd << '\n';
}

int	main(void) {
	ull	a;
	ull	b;

	cin >> a >> b;
	printAnswer(sqrt_ull(b) - sqrt_ull(a), b - a);
	return (0);
}
