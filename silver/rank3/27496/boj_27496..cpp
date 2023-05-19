#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	int	N, L;
	vector<int>	v;
	vector<int>	s;
	int	ans;

	cin >> N >> L;
	v.resize(N + L - 1);
	s.resize(N);
	for (int i = L - 1; i < N + L - 1; i++) {
		cin >> v[i];
		if (i == L - 1)
			s[0] = v[L - 1];
		else
			s[i - L + 1] = s[i - L] - v[i - L] + v[i];
	}
	ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 129 && s[i] <= 138)
			ans++;
	}
	cout << ans << endl;
	return (0);
}