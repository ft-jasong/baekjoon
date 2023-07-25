#include <iostream>

using namespace std;

int answer;

void	recursive(int sum, int target) {
	if (sum > target)
		return ;
	else if (sum == target)
		answer++;
	else {
		recursive(sum + 1, target);
		recursive(sum + 2, target);
		recursive(sum + 3, target);
	}
}

int main(void) {
	int	test_case;
	int	target;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> target;
		answer = 0;
		recursive(0, target);
		cout << answer << '\n';
	}
	return (0);
}