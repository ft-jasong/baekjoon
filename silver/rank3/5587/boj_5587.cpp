#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	findLowestCardIdx(vector<int>& player, int cardNum) {
	int	i;

	i = 0;
	if (cardNum == 0)
		return (0);
	while (i < player.size()) {
		if (player[i] > cardNum)
			return (i);
		i++;
	}
	return (-1);
}

void	playGame(vector<int>& sang, vector<int>& geun) {
	int	flipCard;
	int	delIdx;

	flipCard = 0;
	while (true) {
		delIdx = findLowestCardIdx(sang, flipCard);
		if (delIdx >= 0) {
			flipCard = sang[delIdx];
			sang.erase(sang.begin() + delIdx);
		}
		else
			flipCard = 0;
		if (sang.empty())
			break ;
		delIdx = findLowestCardIdx(geun, flipCard);
		if (delIdx >= 0) {
			flipCard = geun[delIdx];
			geun.erase(geun.begin() + delIdx);
		}
		else
			flipCard = 0;
		if (geun.empty())
			break ;
	}
}

int	main(void) {
	vector<int>	sang;
	vector<int>	geun;
	int			n;
	int			tmp;

	cin >> n;
	sang.reserve(n);
	geun.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sang.push_back(tmp);
	}
	sort(sang.begin(), sang.end());
	for (int i = 1; i <= n * 2; i++) {
		if (find(sang.begin(), sang.end(), i) == sang.end())
			geun.push_back(i);
	}
	playGame(sang, geun);
	cout << geun.size() << '\n' << sang.size() << '\n';
	return (0);
}