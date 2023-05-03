#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<vector<int> >	swirl;
int						r1, c1;
int						r2, c2;

bool isRange(int row, int col) {
	if (row <= r2 && row >= r1 && col <= c2 && col >= c1)
		return (true);
	return (false);
}

void fillSwirlByIdx(int idx) {
	int	startNum;
	int	sideLen;
	int	rowLen = r2 - r1 + 1;
	int	colLen = c2 - c1 + 1;
	int	row;
	int	col;

	startNum = pow(1 + 2 * (idx - 1), 2) + 1;
	sideLen = 1 + idx * 2;
	row = idx;
	col = idx;
	if (idx == 0) {
		if (swirl[0].size() > abs(c1) && swirl.size() > abs(r1))
			swirl[abs(r1)][abs(c1)] = 1;
		return ;
	}
	for (int i = 0; i < sideLen - 1; i++) {
		row--;
		if (isRange(row, col))
			swirl[row - r1][col - c1] = startNum;
		startNum++;
	}
	for (int i = 0; i < sideLen - 1; i++) {
		col--;
		if (isRange(row, col))
			swirl[row - r1][col - c1] = startNum;
		startNum++;
	}
	for (int i = 0; i < sideLen - 1; i++) {
		row++;
		if (isRange(row, col))
			swirl[row - r1][col - c1] = startNum;
		startNum++;
	}
	for (int i = 0; i < sideLen - 1; i++) {
		col++;
		if (isRange(row, col))
			swirl[row - r1][col - c1] = startNum;
		startNum++;
	}
}

void initSwirl(void) {
	for (int row = 0; row < r2 - r1 + 1; row++) {
		swirl.push_back(vector<int>(c2 - c1 + 1));
	}
}

void fillSwirl(int range, int maxIdx) {
	for (int i = maxIdx - range; i <= maxIdx + 1; i++) {
		fillSwirlByIdx(i);
	}
}

pair<int ,int> getRange(void) {
	int maxIdx;
	int range;

	maxIdx = abs(r1);
	if (abs(r2) > maxIdx)
		maxIdx = abs(r2);
	if (abs(c1) > maxIdx)
		maxIdx = abs(c1);
	if (abs(c2) > maxIdx)
		maxIdx = abs(c2);
	range = abs(r1 - r2) > abs(c1 - c2) ? abs(r1 - r2) : abs(c1 - c2);
	return (make_pair(maxIdx, range));
}

void printFormat() {
	int	rowLen = r2 - r1 + 1;
	int	colLen = c2 - c1 + 1;
	int	maxNum;
	int	maxLen;

	maxNum = swirl[0][0];
	if (swirl[rowLen - 1][colLen - 1] > maxNum)
		maxNum = swirl[rowLen - 1][colLen - 1];
	if (swirl[0][colLen - 1] > maxNum)
		maxNum = swirl[0][colLen - 1];
	if (swirl[rowLen - 1][0] > maxNum)
		maxNum = swirl[rowLen - 1][0];
	maxLen = to_string(maxNum).size();
	for (int row = 0; row < rowLen; row++) {
		for (int col = 0; col < colLen; col++) {
			cout << setfill(' ') << setw(maxLen) << right << swirl[row][col] << ' ';
		}
		cout << '\n';
	}
}

int	main(int ac, char *av[]) {
	pair<int, int> maxRange;

	cin >> r1 >> c1 >> r2 >> c2;
	maxRange = getRange();
	initSwirl();
	fillSwirl(maxRange.second, maxRange.first);
	printFormat();
}

// i는 껍질 number, i > 1
// 시작 수 : (1 + 2(i - 1))^2 + 1
// 껍질 한 변: 1 + i * 2
// 올라갈 때: 변 - 1,
//     -3 -2 -1  0  1  2  3
//     --------------------
// -3 |37 36 35 34 33 32 31
// -2 |38 17 16 15 14 13 30
// -1 |39 18  5  4  3 12 29
//  0 |40 19  6  1  2 11 28
//  1 |41 20  7  8  9 10 27
//  2 |42 21 22 23 24 25 26
//  3 |43 44 45 46 47 48 49