#include <iostream>
#include <algorithm>

using namespace std;

int dp1[1000];
int dp2[1000];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int len;
  int arr[1001];
  int maxNum;
  int ans;

  cin >> len;
  for (int i = 0; i < len; i++)
    cin >> arr[i];
  dp1[0] = 0;
  for (int i = 0; i < len; i++) {
    maxNum = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp1[j] > maxNum)
        maxNum = dp1[j];
    }
    dp1[i] = maxNum + 1;
  }
  dp2[len - 1] = 0;
  for (int i = len - 1; i >= 0; i--) {
    maxNum = 0;
    for (int j = len - 1; j > i; j--) {
      if (arr[j] < arr[i] && dp2[j] > maxNum)
        maxNum = dp2[j];
    }
    dp2[i] = maxNum + 1;
  }
  ans = 0;
  for (int i = 0; i < len; i++) {
    ans = max(dp1[i] + dp2[i] - 1, ans);
  }
  cout << ans << '\n';
  return (0);
}
