#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N;
int operands[4]; // + - * /
int numbers[100];
int max_result = -1000000000;
int min_result = 1000000000;

void backtrack(int cur_idx, int plus, int minus, int mul, int div, int cur_sum) {
  if (cur_idx >= N - 1) {
    max_result = max(cur_sum, max_result);
    min_result = min(cur_sum, min_result);
    return ;
  }
  if (plus > 0)
    backtrack(cur_idx + 1, plus - 1, minus, mul, div, cur_sum + numbers[cur_idx + 1]);
  if (minus > 0)
    backtrack(cur_idx + 1, plus, minus - 1, mul, div, cur_sum - numbers[cur_idx + 1]);
  if (mul > 0)
    backtrack(cur_idx + 1, plus, minus, mul - 1, div, cur_sum * numbers[cur_idx + 1]);
  if (div > 0)
    backtrack(cur_idx + 1, plus, minus, mul, div - 1, cur_sum / numbers[cur_idx + 1]);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> numbers[i];
  for (int i = 0; i < 4; i++)
    cin >> operands[i];
  backtrack(0, operands[0], operands[1], operands[2], operands[3], numbers[0]);
  cout << max_result << '\n' << min_result << '\n';
  return (0);
}