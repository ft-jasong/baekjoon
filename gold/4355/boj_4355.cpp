#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
  int N;
  int tmp;
  vector<int> v;

  while (true) {
    cin >> N;
    if (!N)
      break ;
    if (N == 1) {
      cout << 0 << '\n';
      continue ;
    }
    tmp = N;
    for (int i = 2; i <= sqrt(N); i++) {
      if (tmp % i == 0)
        v.push_back(i);
      while (tmp % i == 0) {
        tmp /= i;
      }
      if (tmp == 1)
        break ;
    }
    if (tmp > 1)
      v.push_back(tmp);
    for (int i = 0; i < v.size(); i++) {
      N = (N / v[i]) * (v[i] - 1);
    }
    cout << N << '\n';
    v.clear();
  }
  return (0);
}
