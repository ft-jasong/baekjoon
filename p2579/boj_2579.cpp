#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  vector<int> dpMax;
  vector<int> stair;
  int dpIdx;

  cin >> N;
  stair.resize(N + 1);
  dpMax.resize(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> stair[i];
  if (N == 1) {
    cout << stair[1] << '\n';
    return (0);
  }
  else if (N == 2) {
    cout << stair[1] + stair[2] << '\n';
    return (0);
  }
  dpMax[N] = stair[N];
  dpMax[N - 1] = stair[N] + stair[N - 1];
  dpMax[N - 2] = stair[N] + stair[N - 2];
  dpIdx = N - 3;
  while (dpIdx > 0) {
    if (stair[dpIdx + 1] + dpMax[dpIdx + 3] > dpMax[dpIdx + 2])
      dpMax[dpIdx] = stair[dpIdx + 1] + dpMax[dpIdx + 3] + stair[dpIdx];
    else
      dpMax[dpIdx] = dpMax[dpIdx + 2] + stair[dpIdx];
    --dpIdx;
  }
  cout << (dpMax[1] > dpMax[2] ? dpMax[1] : dpMax[2]) << '\n';
  return (0);
}