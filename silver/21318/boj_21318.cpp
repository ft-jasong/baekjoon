#include <iostream>
#include <vector>

using namespace std;

int	fail_arr[100001];
int	difficulty[100001];

int main(void) {
	int	num;
	int	start;
	int	end;
	int	practice_num;
	int	ans;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> difficulty[i];
	for (int i = 1; i < num; i++) {
		if (difficulty[i] > difficulty[i + 1])
			fail_arr[i] = fail_arr[i - 1] + 1;
		else
			fail_arr[i] = fail_arr[i - 1];
	}
	fail_arr[num] = fail_arr[num - 1];
	cin >> practice_num;
	while (practice_num--) {
		cin >> start >> end;
		// cout << "zero to before start: " << fail_arr[start - 1] << '\n';
		// cout << "zero to end: " << fail_arr[end] << '\n';
		ans = fail_arr[end] - fail_arr[start - 1];
		if (fail_arr[end] > fail_arr[end - 1])
			ans -= 1;
		cout << ans << '\n';
	}
	return (0);
}