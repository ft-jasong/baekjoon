#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(void) {
	long long	ans;
	int	N, K;
	int	rank;
	string	inpt_name;
	vector<vector<int> >	v_name(21);

	ans = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	rank = 0;
	for (int i = 0; i < N; i++) {
		cin >> inpt_name;
		v_name[inpt_name.size()].push_back(rank++);
	}
	for (int name_len = 1; name_len < 21; name_len++) {
		for (int i = 0; i < v_name[name_len].size(); i++) {
			for (int j = i + 1; j < v_name[name_len].size(); j++) {
				if (v_name[name_len][i] + K >= v_name[name_len][j])
					ans++;
				else
					break ;
			}
		}
	}
	cout << ans << '\n';
	return (0);
}