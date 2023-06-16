#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int>	Item;

int	gcd(int a, int b) {
	int	r;	

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

void	abbreviation(Item& item) {
	int	gcd_num;

	gcd_num = gcd(item.first, item.second);
	item.first = item.first / gcd_num;
	item.second = item.second / gcd_num;
}

int	main(void) {
	int	itemNum;
	int	a;
	int	b;
	vector<Item>	items;
	int		mother;
	int		son;
	Item	ans;
	Item	tmp;

	cin >> itemNum;
	items.reserve(itemNum);
	mother = 1;
	for (int i = 0; i < itemNum; i++) {
		cin >> a >> b;
		tmp = make_pair(a, b);
		abbreviation(tmp);
		items.push_back(tmp);
		mother = mother * tmp.second / gcd(mother, tmp.second);
	}
	son = items[0].first * (mother / items[0].second);
	for (int i = 1; i < itemNum; i++) {
		son = gcd(son, items[i].first * (mother / items[i].second));
	}
	ans = make_pair(son, mother);
	abbreviation(ans);
	cout << ans.first << ' ' << ans.second << '\n';
	return (0);
}