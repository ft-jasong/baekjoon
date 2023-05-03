#include <climits>
#include <iostream>
#include <limits.h>
#include <iomanip>
#include <string>

using namespace std;

void printbits(unsigned long long num) {

	int	mask = 63;

	while (mask >= 0) {
		cout << ((num >> mask) & 1);
		mask--;
	}
	cout << '\n';
}

int	main(void) {
	unsigned long long ulmax = 123456789;
	unsigned long long mask = ULONG_LONG_MAX ^ 0b111111111;
	
	cout << ulmax << endl;
	cout << mask << endl;
	printbits(ulmax);
	printbits(mask);
	cout << fixed;
	cout << ((double)ulmax == (double)mask) << endl;
}
