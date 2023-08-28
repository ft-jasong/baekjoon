#include <iostream>
#include <map>

using namespace std;

int	main(void) {
	int				T;
	int				B;
	int				P;
	int				Q;
	int				inptSize;
	int				ans;
	map<int, int>	boxes;
	char			cmd;
	int				mid;
	int				last;
	int				sum;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		boxes.clear();
		cin >> B >> P >> Q;
		inptSize = P + Q;
		while (inptSize--) {
			cin >> cmd >> mid >> last;
			if (cmd == 'P') {
				if (boxes.find(mid) == boxes.end())
					boxes[mid] = last;
				else
					boxes[mid] += last;
			}
			else {
				sum = 0;
				for (auto it = boxes.lower_bound(mid); it->first <= last && it != boxes.end(); it++)
					sum += it->second;
				cout << sum << '\n';
			}
		}
	}
	return (0);
}