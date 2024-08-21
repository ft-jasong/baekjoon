#include <iostream>
#include <algorithm>

int tri[501][501];

using namespace std;

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	for (int y = n - 1; y >= 0; y--) {
		for (int x = 1; x <= y; x++) {
			tri[y][x] += max(tri[y + 1][x], tri[y + 1][x + 1]);
		}
	}
	cout << tri[1][1] << '\n';
	return (0);
}
