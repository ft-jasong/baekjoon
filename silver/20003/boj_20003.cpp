#include <iostream>
#include <utility>

using namespace std;

int	denominator[50]; // 분모
int	numerator[50]; // 분자

int	GCD(int a, int b) {
	int	r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int	LCM(int a, int b) {
	return (a * b / GCD(a, b));
}

int	main(void) {
	int	item_num;
	int	deno_lcm;
	int	num_gcd;

	cin >> item_num;
	deno_lcm = 1;
	for (int i = 0; i < item_num; i++) {
		cin >> numerator[i] >> denominator[i];
		deno_lcm = LCM(deno_lcm, denominator[i]);
	}
	num_gcd = (deno_lcm / denominator[0]) * numerator[0];
	for (int i = 0; i < item_num; i++) {
		num_gcd = GCD(num_gcd, (deno_lcm / denominator[i]) * numerator[i]);
	}
	cout << num_gcd / GCD(num_gcd, deno_lcm) << ' ' << deno_lcm / GCD(num_gcd, deno_lcm) << '\n';
	return (0);
}