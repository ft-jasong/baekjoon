#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	vote_cnt[101];

int main(void) {
	int	pic_size;
	int	vote_size;
	vector<int>	pics;
	int	inpt;

	cin >> pic_size >> vote_size;
	pics.reserve(pic_size);
	while (vote_size--) {
		cin >> inpt;
		if (pics.size() < pic_size && !vote_cnt[inpt]) {
			pics.push_back(inpt);
			vote_cnt[inpt]++;
		}
		else if (vote_cnt[inpt]) {
			vote_cnt[inpt]++;
		}
		else {
			int	min_cnt = 99999;
			int	min_idx;
			min_idx = 0;
			for (int i = 0; i < pics.size(); i++) {
				if (vote_cnt[pics[i]] < min_cnt) {
					min_cnt = vote_cnt[pics[i]];
					min_idx = i;
				}
			}
			vote_cnt[inpt]++;
			vote_cnt[pics[min_idx]] = 0;
			pics.erase(pics.begin() + min_idx);
			pics.push_back(inpt);
		}
	}
	sort(pics.begin(), pics.end());
	for (int i = 0; i < pics.size(); i++)
		cout << pics[i] << ' ';
	cout << '\n';
	return (0);
}