#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>	v_time;
vector<int>	charger;

int main(void) {
	int	N;
	int	K;

	cin >> N >> K;
	v_time.resize(N);
	charger.resize(K);
	for (int i = 0; i < N; i++)
		cin >> v_time[i];
	sort(v_time.begin(), v_time.end(), greater<int>());
	for (auto it = v_time.begin(); it < v_time.end(); it++) {
		charger[0] += *it;
		sort(charger.begin(), charger.end());
	}
	cout << charger[K - 1] << '\n';
	return (0);
}