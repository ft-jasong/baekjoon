#include <iostream>
#include <cmath>

using namespace std;

int	getZ(int posY, int posX) {
	if (posY == 0 && posX == 0) return (0);
	else if (posY == 0 && posX == 1) return (1);
	else if (posY == 1 && posX == 0) return (2);
	else if (posY == 1 && posX == 1) return (3);
	else {
		int	order = 0;
		int	moveX = 0;
		int	moveY = 0;

		while ((int)pow(2, order + 1) <= max(posY, posX))
			order++;
		if (posY - pow(2, order) >= 0) {
			moveY = 1;
			posY -= pow(2, order);
		}
		if (posX - pow(2, order) >= 0) {
			moveX = 1;
			posX -= pow(2, order);
		}
		return getZ(posY, posX) + pow(pow(2, order), 2) * moveX + pow(pow(2, order), 2) * 2 * moveY;
	}
}

int	main(void) {
	int	N, r, c;
	int	ans;

	cin >> N >> r >> c;
	cout << getZ(r, c) << endl;
}