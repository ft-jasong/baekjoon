#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int			max_dup;
	int			length;
	int			num_cnt[100001] = {0, };
	vector<int>	nums;
	int			max_len;
	int			start_idx;

	cin >> length >> max_dup;
	nums.resize(length);
	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}
	start_idx = 0;
	max_len = 0;
	for (int i = 0; i < length; i++) {
		num_cnt[nums[i]]++;
		if (num_cnt[nums[i]] > max_dup) {
			while (start_idx < i) {
				num_cnt[nums[start_idx]]--;
				start_idx++;
				if (nums[start_idx - 1] == nums[i])
					break ;
			}
		}
		else {
			if (max_len < i - start_idx + 1)
				max_len = i - start_idx + 1;
		}
	}
	cout << max_len << endl;
	return (0);
}