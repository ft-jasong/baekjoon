#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {
	string	inpt;
	bool	capslock;
	int		continous_len;
	int		i;
	int		ans;
	int		cur_case;

	cin >> inpt;
	capslock = false;
	i = 0;
	ans = 0;
	while (i < inpt.size()) {
		cur_case = isupper(inpt[i]);
		continous_len = 0;
		while ((i < inpt.size()) && (isupper(inpt[i]) == cur_case)) {
			i++;
			continous_len++;
		}
		if (continous_len == 1 && cur_case != capslock)
			ans += 2;
		else if (continous_len == 1 && cur_case == capslock)
			ans += 1;
		else if (continous_len > 1 && cur_case != capslock) {
			ans += continous_len + 1;
			capslock = !capslock;
		}
		else
			ans += continous_len;
	}
	cout << ans << '\n';
	return (0);
}