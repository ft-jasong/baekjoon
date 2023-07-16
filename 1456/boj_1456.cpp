#include <iostream>
#include <cmath>

using namespace std;

char notPrime[10000001];

int main(void) {
	long long	start;
	long long	end;
	long long	ans;
	long long	i;
	long long	tmp;
	
	cin >> start >> end;
	ans = 0;
	i = 2;
	while (i * i <= end) {
		if (!notPrime[i]) {
			tmp = i;
			while (tmp * i <= end) {
				tmp *= i;
				if (tmp >= start)
					ans++;
			}
			int	j = 0;
			while (i > 1 && ++j * i <= 10000000)
				notPrime[i * j] = 1;
		}
		i++;
	}
	cout << ans << '\n';
	return (0);
}