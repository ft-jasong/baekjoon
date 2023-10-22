#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool isPossible(string &src, string &target) {
  int same;

  if (src.size() != target.size())
    return (false);
  same = 0;
  for (int i = 0; i < src.size(); i++) {
    if (src[i] == 'a')
      same++;
    if (target[i] == 'a')
      same--;
  }
  if (same)
    return (false);
  return (true);
}

int main(void) {
  string src;
  string target;
  int tc;
  int ans;

  cin >> tc;
  while (tc--) {
    cin >> src >> target;
    ans = 0;
    if (!isPossible(src, target)) {
      cout << "-1\n";
      continue;
    }
    int targetIdx = target.size() - 1;
    int srcIdx = src.size() - 1;
    while (targetIdx >= 0) {
      if (target[targetIdx] == 'b') {
        while (src[srcIdx] != 'b')
          srcIdx--;
        ans += abs(targetIdx - srcIdx);
        srcIdx--;
      }
      targetIdx--;
    }
    cout << ans << '\n';
  }
  return (0);
}
