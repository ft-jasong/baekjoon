#include <deque>
#include <iostream>

using namespace std;

int	main(void) {
	deque<int> dq(10);
	deque<int> dq2(10);

	for (int i = 0; i < 20; i++) {
		dq.push_front(i);
		dq2.push_front(i);
	}
	for (auto it = dq.begin(); it != dq.end(); it++) {
		cout << (&*it) << endl;
	}
	return (0);
}
