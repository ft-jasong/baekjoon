#include <iostream>
#include <algorithm>

using namespace std;

bool checkGood(int nums[], int mx) {
  for (int i = 1; i < mx; i++) {
    if (!nums[i])
      return (false);
  }
  return (true);
}

int main(void) {
  int nums[201] = {0, };
  int num;
  int input;
  int mx;
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  mx = 0;
  cin >> num;
  while (num--) {
    cin >> input;
    mx = max(input, mx);
    nums[input] = 1;
  }
  if (checkGood(nums, mx)) {
    cout << "good job\n";
    return (0);
  }
  for (int i = 1; i <= mx; i++) {
    if (!nums[i])
      cout << i << '\n';
  }
  return (0);
}
