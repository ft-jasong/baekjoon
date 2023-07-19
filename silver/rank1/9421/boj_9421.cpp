#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int	prime[1000001];

int	posSquareSum(int num) {
	int	sum;
	int	r;

	sum = 0;
	while (num) {
		r = num % 10;
		sum += r * r;
		num /= 10;
	}
	return (sum);
} 

bool	isHappyPrime(int num) {
	vector<int>	log;
	int			squareSum;

	squareSum = posSquareSum(num);
	while (squareSum != 1) {
		if (squareSum == 1)
			return (true);
		if (find(log.begin(), log.end(), squareSum) != log.end())
			return (false);
		log.push_back(squareSum);
		squareSum = posSquareSum(squareSum);
	}
	return (true);
}

int main(void) {
	int	N;

	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (!prime[i]) {
			int	j = 2;

			while (i * j < 1000001) {
				prime[i * j] =1;
				j++;
			}
			if (isHappyPrime(i))
				cout << i << '\n';
		}
	}
	return (0);
}