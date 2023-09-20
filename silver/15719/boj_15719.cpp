#include <iostream>

using namespace std;

char nums[10000001];

int main(void) {
  int size;
  int tmp;

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> size;
  while (size--) {
    cin >> tmp;
    if (!nums[tmp])
      nums[tmp] = 1;
    else
      cout << tmp << '\n';
  }
  return (0);
}
