#include <iostream>

using namespace std;

int main(void) {
	int	N;
	int	len;

	cin >> N;
	while (N--) {
		cin >> len;
	}
}

10 9 8 7 6 5 4 3 2 1 -> 55
0 : 55
1 : 55 - (10 + 1) = 44
2 : 55 - (10 + 9 + 2)
3 : 55 - (10 + 9 + 8 + 3) 
...
9 : 55 - (10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1)

0 -> 55
1 -> 55 - 10
2 -> 55 - 10 - 9


10 * (이전 sum) - 9 * ()