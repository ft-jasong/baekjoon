#include <iostream>

using namespace std;

int	dp[2000];
int	soilder[2000];

int main(void) {
	int	size;
	int	answer;

	cin >> size;
	for (int i = 0; i < size; i++)
		cin >> soilder[i];
	dp[0] = 1;
	for (int i = 1; i < size; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (dp[i] <= dp[j] && soilder[i] < soilder[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	answer = dp[0];
	for (int i = 0; i < size; i++) {
		if (answer < dp[i])
			answer = dp[i];
	}
	cout << size - answer << '\n';
	return (0);
}