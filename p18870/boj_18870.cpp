#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  int N;
  int origin[1000000];
  int rank;
  unordered_map<int, int> compress;

  cin >> N;
  vector<int> coords(N);
  for (int i = 0; i < N; i++) {
    cin >> coords[i];
    origin[i] = coords[i];
  }
  sort(coords.begin(), coords.end());
  rank = 0;
  for (int i = 0; i < N; i++) {
    if (!compress.count(coords[i]))
      compress[coords[i]] = rank++;
  }
  for (int i = 0; i < N; i++)
    cout << compress[origin[i]] << ' ';
  cout << '\n';
  return (0);
}