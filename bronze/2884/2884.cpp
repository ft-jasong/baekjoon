#include <iostream>

using namespace std;

int main(void) {
  int cal_min;
  int init_hour;
  int init_min;

  cin >> init_hour >> init_min;
  cal_min = 1440 + 60 * init_hour + init_min - 45;
  cout << (cal_min / 60) % 24 << ' ' << cal_min % 60 << '\n';
  return (0);
}
