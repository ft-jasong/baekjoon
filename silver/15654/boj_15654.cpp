#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	prints[8];
int	maxLength;
int	numSize;

bool	checkDup(int number, int depth) {
	for (int i = 0; i < depth; i++) {
		if (prints[i] == number)
			return true;
	}
	return (false);
}

void	backtrack(vector<int>& numbers, int idx, int depth) {
	if (idx > numSize)
		return ;
	if (depth == maxLength) {
		for (int i = 0; i < depth; i++)
			cout << prints[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 0; i < numSize; i++) {
		if (!checkDup(numbers[i], depth)) {
			prints[depth] = numbers[i];
			backtrack(numbers, i, depth + 1);
		}
	}
}

int main(void) {
	vector<int>	numbers;
	cin >> numSize >> maxLength;

	numbers.resize(numSize);
	for (int i = 0; i < numSize; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());
	backtrack(numbers, 0, 0);
	return (0);
}