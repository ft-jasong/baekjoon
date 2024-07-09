#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int ppl_num;
  int start;
  int dest;
  int relation_num;
  int child;
  int parent;
  vector<int> ppls[101];

  cin >> ppl_num;
  cin >> start >> dest;
  cin >> relation_num;
  while (relation_num--) {
    cin >> parent >> child;
    ppls[parent].push_back(child);
  }
}
