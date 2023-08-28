#include <iostream>

using namespace std;

char	num[11];
int		cnt;

void	generateInitNum(int len) {
	int	i;

	i = -1;
	while (++i < len) {
		num[i] = '0' + (len - i - 1);
	}
	num[len] = 0;
	cnt++;
}

void	addNum(int len) {
	
}

bool	findNum(int findIdx) {
	int	len;

	len = 1;
	while (len <= 10) {
		generateInitNum(len);
		if (cnt == findIdx)
			return (true);
		while (num[len - 1] == '9' - (len - 1)) {
			addNum(len);
		}
	}
}

int	main(void) {
	int	N;

	cin >> N;
	cout << num << '\n';
	return (0);
}