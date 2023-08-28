#include <iostream>
#include <string>

using namespace std;

int fibo[43] = {1, 1, 2, 3, 0, };
int	ans;

int	getLen(string& str, int start_idx) {
	int	len;

	len = 0;
	while (start_idx < str.length()) {
		len++;
		if (str[start_idx] >= '4') {
			if (start_idx > 0 && str[start_idx - 1] == '3' && str[start_idx] == '4') {
				ans *= fibo[len];
				return (len);
			}
			else if (start_idx > 0 && str[start_idx - 1] >= '3' && str[start_idx] >= '4') {
				ans *= fibo[len - 1];
				return (len);
			}
			else {
				ans *= fibo[len];
				return (len);
			}
		}
		if (str[start_idx] == '0') {
			if (start_idx == 0 || str[start_idx - 1] > '3')
				ans *= 0;
			ans *= fibo[len - 2];
			return (len);
		}
		start_idx++;
	}
	ans *= fibo[len];
	return (len);
}


int	main(int ac, char *av[]) {
	string	num;
	int	i;

	for (int i = 3; i < 43; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	num = av[ac - 1];
	// cin >> num;
	ans = 1;
	i = 0;
	while (i < num.length()) {
		i += getLen(num, i);
	}
	cout << ans << '\n';
	return (0);
}