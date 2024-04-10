#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int N;
int max_ans;

void backtrack(vector<pair<int, int> >& v, int curr_idx, int curr_sum) {
  if (curr_idx >= N)
    return ;
  // 현재 선택 안하는 경우
  backtrack(v, curr_idx + 1, curr_sum);
  // 현재를 선택한 경우
  if (curr_idx + v[curr_idx].first > N)
    return ;
  if (v[curr_idx].second + curr_sum > max_ans)
    max_ans = v[curr_idx].second + curr_sum;
  backtrack(v, curr_idx + v[curr_idx].first, curr_sum + v[curr_idx].second);
}

int main(void) {
  vector<pair<int, int> > v; // TIME - PAY
  int time;
  int pay;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> time >> pay;
    v.push_back(make_pair(time, pay));
  }
  for (int i = 0; i < N; i++)
    backtrack(v, i, 0);
  cout << max_ans << '\n';
  return (0);
}
