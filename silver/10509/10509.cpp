#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

# define MAX_ROW 4
# define MAX_COL 3

int board[MAX_ROW][MAX_COL] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{-1, 0, -1}
};

int getAns(int input_num, vector<int>& numbers) {
	int diff;
	int ans;
	diff = 987654321;
	ans = numbers[0];
	for (int i = 0; i < numbers.size(); ++i) {
		if (diff > abs(numbers[i] - input_num)) {
			diff = abs(numbers[i] - input_num);
			ans = numbers[i];
		}
	}
	return (ans);
}

int make_num(int *backtrack_stack, int size) {
	int num;

	num = 0;
	for (int i = 0; i < size; i++) {
//		cout << "[i: " << i << "], backtrack_stack: " << backtrack_stack[i] << '\n';
		num = num * 10 + backtrack_stack[i];
	}
//	cout << "CREATED : " << num << '\n';
	return (num);
}

void backtrack(vector<int>& numbers, int *backtrack_stack, int cur_row, int cur_col, int idx) {
	if (cur_row == MAX_ROW || cur_col == MAX_COL || board[cur_row][cur_col] < 0 || idx == 5)
		return ;
	backtrack(numbers, backtrack_stack, cur_row + 1, cur_col, idx);
	backtrack(numbers, backtrack_stack, cur_row, cur_col + 1, idx);
	if (board[cur_row][cur_col] >= 0) {
		backtrack_stack[idx] = board[cur_row][cur_col];
		numbers.push_back(make_num(backtrack_stack, idx + 1));
	}
	backtrack(numbers, backtrack_stack, cur_row + 1, cur_col, idx + 1);
	backtrack(numbers, backtrack_stack, cur_row, cur_col + 1, idx + 1);
	backtrack(numbers, backtrack_stack, cur_row, cur_col, idx + 1);
}

void init_numbers(vector<int>& numbers) {
	int backtrack_stack[5] = {0, };

	backtrack(numbers, backtrack_stack, 0, 0, 0);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> numbers;
	int loop_cnt;
	int input_num;

	init_numbers(numbers);
	cin >> loop_cnt;
	while (loop_cnt--) {
		cin >> input_num;
		cout << getAns(input_num, numbers) << '\n';
	}
	return (0);
}
