#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_index(vector<int>& li, int friend_num) {
    return (find(li.begin(), li.end(), friend_num) - li.begin());
}

int main(void) {
    int list_size;
    int friend_size;
    vector<int> li;
    vector<int> friend_li;
    int ans;

    cin >> list_size >> friend_size;
    li.resize(list_size);
    friend_li.resize(friend_size);
    ans = friend_size;
    for (int i = 0; i < list_size; i++)
        cin >> li[i];
    for (int i = 0; i < friend_size; i++)
        cin >> friend_li[i];
    for (int i = 0; i < friend_size; i++) {
        if (get_index(li, friend_li[i]) < friend_size)
            ans--;
    }
    cout << ans << '\n';
    return (0);
}