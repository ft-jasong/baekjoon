#include <iostream>

using namespace std;

int fibo[46];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num;
  int tmp;

  fibo[0] = 1;
  fibo[1] = 1;
  for (int i = 2; i < 46; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  cin >> num;
  while (num--) {
    cin >> tmp;
    cout << fibo[tmp] << '\n';
  }
  return (0);
}
