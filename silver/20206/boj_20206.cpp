#include <iostream>

using namespace std;

int	a, b, c;

double	getYfromX(int x) {
	// ax + by + c => (a * x + c) / b == y
	return (a * x + c) / (double)(-b);
}

int	main(void) {
	int	xmin, xmax, ymin, ymax;

	cin >> a >> b >> c;
	cin >> xmin >> xmax >> ymin >> ymax;
	if (a * b < 0) { // 그래프 우상향
		if (getYfromX(xmin) < ymax && getYfromX(xmax) > ymin)
			cout << "Poor\n";
		else
			cout << "Lucky\n";
	}
	else if (a * b > 0) { // 그래프 우하향
		if (getYfromX(xmin) > ymin && getYfromX(xmax) < ymax)
			cout << "Poor\n";
		else
			cout << "Lucky\n";
	}
	else { // 그래프 직선
		if (!a && (double)(-c) / b > ymin && (double)(-c) / b < ymax)
			cout << "Poor\n";
		else if (!b && (double)(-c) / a > xmin && (double)(-c) / a < xmax)
			cout << "Poor\n";
		else
			cout << "Lucky\n";
	}
	return (0);
}