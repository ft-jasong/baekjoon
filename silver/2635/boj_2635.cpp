#include <iostream>

using namespace std;

int	start_max;
int	count_max;

void	findMax(int n, int minus) {
	int	tmp;
	int	input_tmp;
	int	count;

	tmp = n;
	count = 0;
	input_tmp = minus;
	while (n >= 0) {
		count++;
		tmp = minus;
		minus = n - minus;
		n = tmp;
	}
	if (count > count_max) {
		start_max = input_tmp;
		count_max = count;
	}
}

int	main(void) {
	int	N;
	int	tmp;

	cin >> N;
	for (int start = N / 2; start <= N; start++) {
		findMax(N, start);
	}
	cout << count_max << '\n';
	cout << N << ' ';
	while (N >= 0) {
		if (start_max < 0)
			break ;
		cout << start_max << ' ';
		tmp = start_max;
		start_max = N - start_max;
		N = tmp;
	}
	return (0);
}