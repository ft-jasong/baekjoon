#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main(void) {
	int	test_case;
	string	type;
	string	name;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int	tests;
		int	answer;
		unordered_map<string, set<string> > dress;

		cin >> tests;
		while (tests--) {
			cin >> name >> type;
			dress[type].insert(name);
		}
		answer = 1;
		for (auto it = dress.begin(); it != dress.end(); it++)
			answer = answer * (it->second.size() + 1);
		cout << answer - 1 << '\n';
	}
	return (0);
}