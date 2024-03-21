#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int	food_size;
	int	init_len;
	vector<int> foods;

	cin >> food_size >> init_len;
	foods.resize(food_size);
	for (int i = 0; i < food_size; i++) {
		cin >> foods[i];
	}
	sort(foods.begin(), foods.end(), less<int>());
	for (int i = 0; i < food_size; i++) {
		if (init_len >= foods[i])
			init_len++;
		else
			break ;
	}
	cout << init_len << '\n';
	return (0);
}
