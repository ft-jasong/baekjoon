#include <iostream>

using namespace std;

long long route[100001][2];

int main(void) {
  int test_case;

  route[1][0] = 0;
  route[1][1] = 1;
  route[2][0] = 1;
  route[2][1] = 1;
  route[3][0] = 2;
  route[3][1] = 2;
  for (int i = 4; i <= 100000; i++) {
    route[i][0] = (route[i - 3][1] + route[i - 2][1] + route[i - 1][1]) % 1000000009;
    route[i][1] = (route[i - 3][0] + route[i - 2][0] + route[i - 1][0]) % 1000000009;
  }
  cin >> test_case;
  for (int t = 0; t < test_case; t++) {
    int num;

    cin >> num;
    cout << route[num][1] << ' ' << route[num][0] << '\n';
  }
  return (0);
}