#include <iostream>

using namespace std;

int main(void) {
	int	i = -1;
	double	input;
	size_t	sum = 0;
	size_t	decimal = 0;
	int		underpoint[5] = {0, };

	while (++i < 12) {
		cin >> input;
		sum += input * 100;
	}
	decimal = sum / 1200;
	cout << '$';
	sum = sum % 1200;
	for (i = 0; i < 5; i++) {
		sum *= 10;
		underpoint[i] = sum / 1200;
		sum = sum % 1200;
	}
	if (underpoint[3] == 9 && underpoint[4] == 9)
		underpoint[2]++;
	if (underpoint[2] >= 5) {
		underpoint[1]++;
		if (underpoint[1] >= 10) {
			underpoint[0]++;
			underpoint[1] -= 10;
		}
		if (underpoint[0] >= 10) {
			decimal++;
			underpoint[0] -= 10;
		}
	}
	cout << decimal << '.' << underpoint[0] << underpoint[1] << endl;
	return (0);
}