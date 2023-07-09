#include <iostream>
#include <vector>

#define FACTMAX 1000000000000000000LL

using namespace std;

int main(void) {
	long long	num;
	long long	tmp;
	vector<long long>	fact;
	int	i;

	cin >> num;
	fact.push_back(1);
	i = 1;
	if (!num) {
		cout << "NO\n";
		return (0);
	}
	while (fact.back() * i < FACTMAX) {
		fact.push_back(fact.back() * i);
		i++;
	}
	for (vector<long long>::reverse_iterator rit = fact.rbegin(); rit < fact.rend(); rit++) {
		if (*rit <= num)
			num -= *rit;
		if (num == 0)
			break ;
	}
	if (num == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return (0);
}