#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;


char board[1002][1002];
char player_visited[1002][1002];
int row;
int col;
int ans = -1;

void update_fire(void) {
  char new_fire_board[1001][1001] = {0, };

  for (int r = 1; r <= row; r++) {
    for (int c = 1; c <= col; c++) {
      if (board[r][c] != 'F') {
        if (!new_fire_board[r][c])
          new_fire_board[r][c] = board[r][c];
      }
      else {
        new_fire_board[r][c] = 'F';
        if (r - 1 > 0 && board[r - 1][c] != '#')
          new_fire_board[r - 1][c] = 'F';
        if (r + 1 <= row && board[r + 1][c] != '#')
          new_fire_board[r + 1][c] = 'F';
        if (c - 1 > 0 && board[r][c - 1] != '#')
          new_fire_board[r][c - 1] = 'F';
        if (c + 1 <= col && board[r][c + 1] != '#')
          new_fire_board[r][c + 1] = 'F';
      }
    }
  }
  for (int r = 0; r <= row; r++) {
    memcpy(board[r], new_fire_board[r], sizeof(board[r]));
  }
//  cout << "NEW FIRE BOARD\n";
//  for (int r = 1; r <= row; r++) {
//    cout << (new_fire_board[r] + 1) << '\n';
//  }
}

bool isEnd(int pos_r, int pos_c) {
  return (pos_r == 1 || pos_r == row || pos_c == 1 || pos_c == col);
}

int bfs(int pos_r, int pos_c) {
  queue<pair<pair<int, int>, int> > q;
  pair<pair<int, int>, int> info;
  int cur_r;
  int cur_c;
  int pre_move = 1;
  int cur_move = 1;

  info = make_pair(make_pair(pos_r, pos_c), 1);
  q.push(info);
  player_visited[pos_r][pos_c] = 1;
  while (!q.empty()) {
    cur_r = q.front().first.first;
    cur_c = q.front().first.second;
    cur_move = q.front().second;
    q.pop();
    if (isEnd(cur_r, cur_c))
      return (cur_move);
    if (pre_move < cur_move)
        update_fire();
    pre_move = cur_move;
    if (cur_r - 1 > 0 && !player_visited[cur_r - 1][cur_c] && board[cur_r - 1][cur_c] == '.') {
      player_visited[cur_r - 1][cur_c] = 1;
      q.push(make_pair(make_pair(cur_r - 1, cur_c), cur_move + 1));
    }
    if (cur_r + 1 <= row && !player_visited[cur_r + 1][cur_c] && board[cur_r + 1][cur_c] == '.') {
      player_visited[cur_r + 1][cur_c] = 1;
      q.push(make_pair(make_pair(cur_r + 1, cur_c), cur_move + 1));
    }
    if (cur_c - 1 > 0 && !player_visited[cur_r][cur_c - 1] && board[cur_r][cur_c - 1] == '.') {
      player_visited[cur_r][cur_c - 1] = 1;
      q.push(make_pair(make_pair(cur_r, cur_c - 1), cur_move + 1));
    }
    if (cur_c + 1 <= col && !player_visited[cur_r][cur_c + 1] && board[cur_r][cur_c + 1] == '.') {
      player_visited[cur_r][cur_c + 1] = 1;
      q.push(make_pair(make_pair(cur_r, cur_c + 1), cur_move + 1));
    }
  }
  return (-1);
}

int main(void) {
  int j_r;
  int j_c;
  cin >> row >> col;

  for (int r = 1; r <= row; r++) {
    for (int c = 1; c <= col; c++) {
      cin >> board[r][c];
      if (board[r][c] == 'J') {
        j_r = r;
        j_c = c;
      }
    }
  }
  ans = bfs(j_r, j_c);
  if (ans < 0)
    cout << "IMPOSSIBLE\n";
  else
    cout << ans << '\n';
  return (0);
}
