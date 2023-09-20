#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull getPhi(ull num) {
  int ret = 1;

  for (int i = 2; i <= (ull)sqrt(num); i++) {
    int count = 0;
    while (num % i == 0) {
      num /= i;
      count++;
    }
    if (count)
      ret *= pow(i, count - 1) * (i - 1);
  }
  if (num > 1)
    ret *= (num - 1);
  return (ret);
}

int main(void) {
  int num;
  int ans;

  ans = 0;
  cin >> num;
  for (int i = 2; i <= num; i++) {
    ans += getPhi(i);
  }
  cout << ans << '\n';
  return (0);
}
