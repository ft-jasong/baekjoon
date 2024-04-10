#include <iostream>
#include <deque>
#include <string>

using namespace std;

#define N 0
#define S 1

#define RIGHT 1
#define LEFT -1

// 2번째랑 6번째가 맞물림.

void rotate(deque<int>& gear, int dir) {
  int tmp;

  if (dir == RIGHT) {
    tmp = gear.back();
    gear.pop_back();
    gear.push_front(tmp);
  }
  else {
    tmp = gear.front();
    gear.pop_front();
    gear.push_back(tmp);
  }
}

void recursive(deque<int> gears[], int idx, int rotate_dir, int heading) {
  int next_dir;

  if (idx < 0 || idx >= 4)
    return ;
  next_dir = rotate_dir == RIGHT ? LEFT : RIGHT;
  if (heading == LEFT) {
    if (gears[idx][2] != gears[idx + 1][6]) {
      recursive(gears, idx - 1, next_dir, LEFT);
      rotate(gears[idx], next_dir);
    }
  }
  else {
    if (gears[idx][6] != gears[idx - 1][2]) {
      recursive(gears, idx + 1, next_dir, RIGHT);
      rotate(gears[idx], next_dir);
    }
  }
}

void print_gears(deque<int> gears[]) {
  for (int i = 0; i < 4; i++) {
    cout << "deque[" << i << "] : ";
    for (auto it = gears[i].begin(); it < gears[i].end(); it++) {
      cout << *it;
    }
    cout << '\n';
  }
}

int main(void) {
  deque<int> gears[4];
  string tmp;
  int rotate_cnt;
  int gear_num;
  int rotate_dir;
  int ans;

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 4; i++) {
    cin >> tmp;
    for (auto it = tmp.begin(); it < tmp.end(); it++)
      gears[i].push_back(*it - '0');
  }
  cin >> rotate_cnt;
  while (rotate_cnt--) {
    cin >> gear_num >> rotate_dir;
    gear_num = gear_num - 1;
    recursive(gears, gear_num - 1, rotate_dir, LEFT);
    recursive(gears, gear_num + 1, rotate_dir, RIGHT);
    rotate(gears[gear_num], rotate_dir);
  }
  ans = 0;
  for (int i = 0; i < 4; i++) {
    if (gears[i].front() == S) {
      ans += (1 << i);
    }
  }
  cout << ans << '\n';
  return (0);
}
