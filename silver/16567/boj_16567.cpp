#include <iostream>

using namespace std;

int bRoad[1000000] = {0, };

void getbRoad(int *bRoad, int size) {
for (int i = 0; i < size; i++) {
    cin >> bRoad[i];
  }
}

void runTest(int *bRoad, int roadSize, int testSize) {
  int flip;
  bool flipFlag;

  flip = 0;
  flipFlag = true;
  for (int i = 0; i < roadSize; i++) {
    if (flipFlag && bRoad[i]) {
      ++flip;
      flipFlag = false;
    }
    if (!bRoad[i])
      flipFlag = true;
  }
  for (int i = 0; i < testSize; i++) {
    int test;
    int num;

    cin >> test;
    if (test) {
      cin >> num;
      if (bRoad[num - 1])
        continue ;
      else {
        bRoad[num - 1] = 1;
        if (num - 1 == 0 && bRoad[num])
          continue ;
        else if (num == roadSize - 1 && bRoad[num - 2])
          continue ;
        else if (bRoad[num] && bRoad[num - 2])
          flip--;
        else if (!bRoad[num] && !bRoad[num - 2])
          flip++;
        else
          continue ;
      }
    }
    else
      cout << flip << '\n';
  }
}

int main(void) {
  int N;
  int M;

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  getbRoad(bRoad, N);
  runTest(bRoad, N, M);
  return (0);
}