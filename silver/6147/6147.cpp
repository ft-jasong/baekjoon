#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int cow_num;
  int shelf_height;
  vector<int> cows;
  int sum;

  cin >> cow_num >> shelf_height;
  while (cow_num--) {
    int cow_height;

    cin >> cow_height;
    cows.push_back(cow_height);
  }
  sort(cows.begin(), cows.end(), greater<int>());
  sum = 0;
  for (int i = 0; i < cows.size(); i++) {
    sum += cows[i];
    if (sum >= shelf_height) {
      cout << i + 1 << '\n';
      break ;
    }
  }
  return (0);
}
