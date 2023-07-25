#include <iostream>

using namespace std;

int	main(void) {
	long long	count, day;
	long long	happiness;
	long long	maxNoGloomDay;
	long long	gloomyCount;
	long long	ans = 0;
	long long	m;
	long long	r;

	cin >> count >> day;
	maxNoGloomDay = 0;
	if (!count) {
		cout << (day * (day + 1) * (2 * day + 1) / 6) << '\n';
		return (0);
	}
	for (int i = 0; i < count; i++) {
		cin >> happiness;
		maxNoGloomDay += happiness + 1;
	}
	gloomyCount = day - maxNoGloomDay;
	if (gloomyCount <= 0) {
		cout << 0 << '\n';
		return (0);
	}
	m = gloomyCount / (count + 1);
	r = gloomyCount % (count + 1);
	ans += ((m + 1) * (m + 2) * (2 * (m + 1) + 1) / 6) * r;
	ans += (m * (m + 1) * (2 * m + 1) / 6) * (count + 1 - r);
	cout << ans << '\n';
	return (0);
}