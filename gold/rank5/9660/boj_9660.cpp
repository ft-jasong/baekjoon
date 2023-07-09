#include <iostream>

using namespace std;

int main(void) {
	char		ans[7][3] = {"SK", "CY", "SK", "SK", "SK", "SK", "CY"};
	long long	N;

	cin >> N;
	cout << ans[(N - 1) % 7] << '\n';
	return (0);
}