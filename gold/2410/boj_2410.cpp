#include <iostream>

using namespace std;

long long ans[1000001];

int main(void) {

  int num;

  cin >> num;
  ans[1] = 1;
  ans[2] = 2;
  for (int i = 3; i <= num; i++) {
    for (int j = 1; j <= i / 2; j++) {
      ans[i] += (ans[i - j] + ans[j]) % 1000000000;
    }
  }
  cout << ans[num] << '\n';
  return (0);
}
