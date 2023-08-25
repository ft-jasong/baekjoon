#include <iostream>

using namespace std;

char	board[100][100];

int	main(void) {
	bool	open;
	int		fullCnt;
	int		halfCnt;
	int		h;
	int		w;
	char	inpt;

	cin >> h >> w;
	halfCnt = 0;
	fullCnt = 0;
	for (int row = 0; row < h; row++) {
		open = false;
		for (int col = 0; col < w; col++) {
			cin >> inpt;
			if (!open) {
				if (inpt == '\\' || inpt == '/') {
					open = true;
					halfCnt++;
				}
			}
			else {
				if (inpt == '.')
					fullCnt++;
				else {
					open = false;
					halfCnt++;
				}
			}
		}
	}
	cout << fullCnt + halfCnt / 2 << '\n';
	return (0);
}