#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= k) {
            k -= arr[i];
            ++ans;
        }
        else break;
    }
    cout << ans;
    return 0;
}
