#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int size;
    vector<int> v;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> size;
    v.resize(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), less<int>());
    for (auto it = v.begin(); it < v.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    return (0);
}
