#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long			input;
	long long			count;
	long long			answer;

	cin >> input;
	answer = 1;
	if (input == 1) {
		cout << answer << '\n';
		return (0);
	}
	for (int i = 2; i <= (int)sqrt(input); i++) {
		count = 0;
		if (input == 0)
			break ;
		while (input % i == 0) {
			input /= i;
			++count;
		}
		if (count > 0)
			answer *= (long long)pow(i, count - 1) * (i - 1);
	}
	if (input > 1)
		answer *= (input - 1);
	cout << answer << '\n';
	return (0);
}