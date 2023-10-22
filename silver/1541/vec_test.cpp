#include <iostream>
#include <vector>

using namespace std;

vector<int> vec_test(void) {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    return (v);
}

int main(void) {
    vector<int> v;

    v = vec_test();
    for (auto it = v.begin(); it < v.end(); it++)
        cout << *it << ' ';
    return (0);
}
