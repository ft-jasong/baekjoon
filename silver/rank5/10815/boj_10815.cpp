#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	unordered_map<int, int>	deck;
	int	N;
	int	cardNum;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while (N--) {
		cin >> cardNum;
		deck[cardNum] = 1;
	}
	cin >> N;
	while (N--) {
		cin >> cardNum;
		if (deck.count(cardNum))
			cout << "1 ";
		else
			cout << "0 ";
	}
	return (0);
}