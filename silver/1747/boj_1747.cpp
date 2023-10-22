#include <iostream>
#include <string>

using namespace std;

char isNotPrime[10000001];

bool isPelindrome(int num) {
  string numStr;

  numStr = to_string(num);
  for (int i = 0; i < numStr.length() / 2; i++) {
    if (numStr[i] != numStr[numStr.length() - 1 - i])
      return (false);
  }
  return (true);
}

int main(void) {
  int num;
  int idx;

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> num;
  idx = 2;
  if (num == 1) {
    cout << 2 << '\n';
    return (0);
  }
  while (true) {
    if (idx >= num && !isNotPrime[idx] && isPelindrome(idx)) {
      cout << idx;
      return (0);
    }
    if (!isNotPrime[idx]) {
      int j = 2;
      while (j * idx <= 10000000) {
        isNotPrime[idx * j] = 1;
        j++;
      }
    }
    idx++;
  }
  return (0);
}
