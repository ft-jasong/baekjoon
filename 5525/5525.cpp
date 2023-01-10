#include <iostream>
#include <string>
#include <vector>

#define IFLAG 1

using namespace std;

int	main(void) {
	string	str;
	vector<int>	v_len;
	int	i;
	int	s_len;
	int	flag;
	int	sum;
	int	N, M;

	cin >> N >> M >> str;
	i = -1;
	while (str[++i]) {
		if (str[i] == 'I') {
			flag = !IFLAG;
			s_len = 0;
			while (++i <= M) {
				if (flag == !IFLAG && str[i] == 'O')
					flag = !flag;
				else if (flag == IFLAG && str[i] == 'I') {
					flag = !flag;
					s_len++;
				}
				else if (i >= M && flag == !IFLAG)
					v_len.push_back(s_len);
				else {
					v_len.push_back(s_len);
					i--;
					break;
				}
			}
		}
	}
	sum = 0;
	for (int i = 0; i < v_len.size(); i++) {
		if (v_len[i] - N + 1 > 0)
			sum += v_len[i] - N + 1;
	}
	cout << sum << '\n';
	return (0);
}