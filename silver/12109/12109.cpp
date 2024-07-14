#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cites[1000001] = {0, };
	int paper_num;
	int tmp;

	cin >> paper_num;
	for (int i = 0; i < paper_num; i++) {
		cin >> tmp;
		cites[tmp]++;
	}
	int count;
	count = 0;
	for (int i = 1000000; i >= 1; i--) {
		count += cites[i];
		if (count >= i) {
			cout << i << '\n';
			return (0);
		}
	}
	return (0);
}
