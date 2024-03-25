#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solution(vector<int>& acid, vector<int>& alkaline) {
    int acid_max_idx = acid.size();
    int alkaline_max_idx = alkaline.size();
    int acid_idx = 0;
    int alkaline_idx = 0;
    int acid_ans = 0;
    int alkaline_ans = 0;

    if (acid.empty()) {
        cout << alkaline[0] << ' ' << alkaline[1] << '\n';
        return ;
    }
    if (alkaline.empty()) {
        cout << acid[0] << ' ' << acid[1] << '\n';
        return ;
    }
    while (acid_idx < acid_max_idx && alkaline_idx < alkaline_max_idx) {
        
    }
    cout << alkaline[alkaline_ans] << ' ' << acid[acid_ans] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> acid;
    vector<int> alkaline;
    int N;
    int tmp;

    cin >> N;
    acid.reserve(N);
    alkaline.reserve(N);
    while (N--) {
        cin >> tmp;
        if (tmp < 0)
            alkaline.push_back(tmp);
        else
            acid.push_back(tmp);
    }
    sort(acid.begin(), acid.end(), less<int>());
    sort(alkaline.begin(), alkaline.end(), greater<int>());
    return (0);
}
