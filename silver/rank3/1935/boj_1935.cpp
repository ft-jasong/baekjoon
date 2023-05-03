#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

double	calculate(string& expression, unordered_map<char, int>& mp) {
	vector<double>	stack;
	double			a;
	double			b;

	for (auto it = expression.begin(); it < expression.end(); it++) {
		if (isalpha(*it))
			stack.push_back(mp[*it]);
		else {
			b = stack.back();
			stack.pop_back();
			a = stack.back();
			stack.pop_back();
			if (*it == '+')
				stack.push_back(a + b);
			if (*it == '-')
				stack.push_back(a - b);
			if (*it == '*')
				stack.push_back(a * b);
			if (*it == '/')
				stack.push_back(a / b);
		}
	}
	return (stack.back());
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int							operand_cnt;
	string						expression;
	char						init_alpha;
	int							input_num;
	unordered_map<char, int>	mp;

	init_alpha = 'A';
	cin >> operand_cnt;
	cin >> expression;
	while (operand_cnt--) {
		cin >> input_num;
		mp[init_alpha] = input_num;
		init_alpha++;
	}
	cout.precision(2);
	cout << fixed << calculate(expression, mp) << '\n';
}