#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  int mx_height;
  int mx_class;
  int participants_classes;
  int ans;
  int min_distance = 987654321;

  cin >> mx_height >> mx_class >> participants_classes;
  for (int i = 0; i < participants_classes; i++) {
    int x, y;
    int distance;

    cin >> y >> x;
    distance = abs(y - 1) + abs(mx_class + 1 - x);
    if (distance < min_distance) {
      ans = i + 1;
      min_distance = distance;
    }
  }
  cout << ans << '\n';
  return (0);
}
