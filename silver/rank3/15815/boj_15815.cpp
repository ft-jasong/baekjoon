#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int	calculate(string& expression) {
	vector<int>	stack;
	int			a;
	int			b;

	for (auto it = expression.begin(); it < expression.end(); it++) {
		if (isalnum(*it))
			stack.push_back(*it - '0');
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

	string	expression;
	cin >> expression;
	cout << calculate(expression) << '\n';
	return (0);
}