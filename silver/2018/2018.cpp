#include <iostream>

using namespace std;

int main(void) {
	int N;
	int _sum;
	int start;
	int end;
	int ans;

	cin >> N;
	start = 0;
	end = 0;
	_sum = 0;
	ans = 0;
	while (end <= N) {
		if (_sum < N) {
			++end;
			_sum += end;
		}
		else if (_sum > N) {
			++start;
			_sum -= start;
		}
		else {
			++ans;
			++end;
			_sum += end;
		}
	}
	cout << ans << '\n';
	return (0);
}
