#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int	nums[10] = {0, };
	string	inpt;
	int		answer;

	cin >> inpt;
	for (int i = 0; i < inpt.length(); i++)
		nums[inpt[i] - '0']++;
	nums[6] += nums[9];
	nums[6] = (nums[6] + 1) / 2;
	nums[9] = 0;
	answer = 0;
	for (int i = 0; i < 10; i++)
		answer = max(answer, nums[i]);
	cout << answer << endl;
	return (0);
}