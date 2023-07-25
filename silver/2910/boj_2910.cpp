#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
  return (p1.second > p2.second);
}

int  findIdxByKey(vector<pair<int, int> >& v, int key) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == key)
      return (i);
  }
  return (-1);
}

int main(void) {
  int N, C;
  vector<pair<int, int> > v;

  cin >> N >> C;
  v.reserve(N);
  while (N--) {
    int tmp;
    int idx;

    cin >> tmp;
    idx = findIdxByKey(v, tmp);
    if (idx < 0)
      v.push_back(make_pair(tmp, 1));
    else
      v[idx].second += 1;
  }
  stable_sort(v.begin(), v.end(), comp);
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].second; j++)
      cout << v[i].first << ' ';
  }
  cout << '\n';
  return (0);
}