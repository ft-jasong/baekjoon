#include <iostream>
#include <cmath>

using namespace std;

int possibleNum[6] = {1, 2, 3, 5, 7, 9};
int maxDepth;

bool isPrime(int n) {
	if (n <= 1)
		return (false);
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return (false);
	}
	return (true);
}

void backtrack(int depth, int num) {
	if (depth && !isPrime(num)) 
		return ;
	if (depth == maxDepth) {
		cout << num << '\n';
		return ;
	}
	for (int i = 0; i < 6; i++) {
		backtrack(depth + 1, num * 10 + possibleNum[i]);
	}
}

int main(void) {
	cin >> maxDepth;

	backtrack(0, 0);
	return (0);
}
