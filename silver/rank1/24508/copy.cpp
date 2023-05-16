#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long	total_sum;
long long	removed_sum;
long long	move_sum;
vector<int>	bag(100000);

int	main(void) {
	int	N, K, T;
	int	num;
	long long	least;
	int	idx;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> T;
	for (int i = 0; i < N; i++) {
		cin >> num;
		total_sum += num;
		bag[i] = num % K;
		removed_sum += (num / K) * K;
	}
	// cout << "sum : " << total_sum << '\n';
	// cout << "K : " << K << '\n';
	if (total_sum % K != 0) {
		cout << "NO" << '\n';
		return (0);
	}
	sort(bag.begin(), bag.end(), greater<int>());
	idx = 0;
	while (idx < N && removed_sum < total_sum) {
		cout << "bag : " << bag[idx] << '\n';
		removed_sum += K;
		move_sum += K - bag[idx];
		idx++;
	}
	// cout << "move sum : " << move_sum << endl;
	// cout << "T : " << T << endl;
	if (move_sum <= T)
		cout << "YES\n";
	else
		cout << "NO\n";
	return (0);
}
