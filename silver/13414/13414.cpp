#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	vector<int> ans;
	int K;
	int L;
	int tmp;

	v.reserve(100000);
	ans.reserve(100000);
	cin >> K >> L;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
}
