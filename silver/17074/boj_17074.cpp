#include <iostream>
#include <vector>

using namespace std;

int	arr[100000];

int main(void) {
	int	len;
	vector<int>	discrete;

	cin >> len;
	discrete.reserve(100000);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
		if (i > 0 && arr[i] < arr[i - 1]) {
			discrete.push_back(i - 1);
		}
		
	}
}