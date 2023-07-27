#include <iostream>
#include <vector>

using namespace std;

int	getMSB(int n) {
	int	msb;

	msb = 0;
	while (n) {
		n /= 2;
		msb++;
	}
	return (msb);
}

int	main(void) {
	int	n;
	vector<int>	v;

	cin >> n;
	v.resize(n + 1);
	for (int i = n; i >= 1; i--) {
		if (!v[i] && (1 << (getMSB(i) - 1)) != i) {
			v[i] = (1 << getMSB(i)) - i;
			v[(1 << getMSB(i)) - i] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i])
			cout << i << '\n';
		else
			cout << v[i] << '\n';
	}
}

