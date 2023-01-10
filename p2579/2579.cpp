#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	int	N;
	int	step_num;
	vector <int> v;
	int	max_;

	cin >> N;
	v.push_back(0);
	for (int i = 0; i < N; ++i) {
		cin >> step_num;
		v.push_back(step_num);
	}
	cout << max_ << endl;
	return (0);
}
