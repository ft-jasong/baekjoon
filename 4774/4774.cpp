#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main(void) {
	std::vector<std::string>	str_v(12);
	int							_sum;
	int							remain;
	int							under_point = 0;

	for (int i = 0; i < 12; i++) {
		std::cin >> str_v[i];
		for (int j = 0; j < str_v[i].length(); j++) {
			if (str_v[i][j] == '.') {
				str_v[i].erase(str_v[i].begin()+ j);
				break;
			}
		}
		_sum += std::stoi(str_v[i]);
	}
	std:: cout << '$' << _sum / 1200 << '.';
	remain = _sum % 1200;
	while (under_point < 100) {
		remain *= 10;
		under_point = under_point * 10 + remain / 1200;
		remain = remain % 1200;
	}
	if (under_point % 10 > 5)
		under_point = under_point / 10 + 1;
	else
		under_point = under_point / 10;
	std::cout << under_point;
}