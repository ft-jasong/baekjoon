#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
      vector<string> v;
      int N;
      bool found = false;
      cin >> N;

      for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
      }
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (i == j) {
            continue;
          }
          if (is_palindrome(v[i] + v[j])) {
            cout << v[i] + v[j] << endl;
            found = true;
          }
        }
        if (found) {
          break;
        }
      }
      if (!found) {
        cout << 0 << endl;
      }
    }
    return 0;
}