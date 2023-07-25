#include <iostream>

using namespace std;

int main(void) {
	int N;
	int a;
	int b;
	int	ans;

	cin >> N >> a >> b;
	ans = 1000001;
	for (int i = 0; i <= N / (a + 1); i++) {
		int	tmp;

		tmp = i + (N - (a + 1) * i) / (b + 1) + (N - (a + 1) * i) % (b + 1);
		if (tmp < ans)
			ans = tmp;
	}
	cout << ans << '\n';
	return (0);
}