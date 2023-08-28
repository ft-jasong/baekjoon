#include <iostream>
#include <cstring>

char str[101];
int	selected[101];

using namespace std;

void	printStr(void) {
	int	i;

	i = -1;
	while (str[++i]) {
		if (selected[i])
			cout << str[i];
	}
	cout << '\n';
}

void	recursiveMake(int startIdx, int maxLen) {
	int		idx;
	char	c;

	while (true) {
		idx = -1;
		c = 127;
		for (int i = startIdx; i < maxLen; i++) {
			if (!selected[i] && str[i] < c) {
				c = str[i];
				idx = i;
			}
		}
		if (idx < 0)
			break ;
		selected[idx] = 1;
		printStr();
		recursiveMake(idx + 1, maxLen);
	}
}

int main(void) {
	int	maxLen;

	cin >> str;
	maxLen = strlen(str);
	recursiveMake(0, maxLen);
	return (0);
}