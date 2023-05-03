#include <iostream>

typedef unsigned long long ull;

using namespace std;
int main(void) {
	ull	queryNum;
	ull	inptNum;
	ull	tc;
	ull	sum;
	ull	exor;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	sum = 0;
	exor = 0;
	while (tc--) {
		cin >> queryNum;
		if (queryNum == 1) {
			cin >> inptNum;
			sum += inptNum;
			exor ^= inptNum;
		}
		else if (queryNum == 2) {
			cin >> inptNum;
			sum -= inptNum;
			exor ^= inptNum;
		}
		else if (queryNum == 3)
			cout << sum << '\n';
		else
			cout << exor << '\n';
	}
	return (0);
}