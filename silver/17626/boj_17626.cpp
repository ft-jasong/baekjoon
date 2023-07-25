#include <iostream>
#include <cmath>

using namespace std;

int	find_ans(int N) {
	int	ans;
	int	tmp;

	ans = 4;
	for (int i = sqrt(N); i > 0; i--) {
		if (i * i == N)
			return (1);
		for (int j = sqrt(N - i * i); j > 0; j--) {
			if (j * j == N - i * i)
				return (2);
			for (int k = sqrt(N - i * i - j * j); k > 0; k--) {
				if (k * k == N - i * i - j * j)
					ans = 3;
			}
		}
	}
	return (ans);
}

int	main(void) {
	int	N;

	cin >> N;
	cout << find_ans(N) << '\n';
}