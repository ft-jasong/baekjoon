#include<iostream>
#include <functional>
#include <queue>

using namespace std;

int	main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	priority_queue<int> q_max;
	priority_queue<int, vector<int>, greater<int> > q_min;
	int	n;
	int	input;
	int	max_top;
	int	min_top;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		if (q_max.size() == 0)
			q_max.push(input);
		else
		{
			if (q_min.size() < q_max.size())
				q_min.push(input);
			else
				q_max.push(input);
			if (q_max.top() > q_min.top())
			{
				min_top = q_min.top();
				max_top = q_max.top();
				q_max.pop();
				q_min.pop();
				q_max.push(min_top);
				q_min.push(max_top);
			}
		}
		std::cout << q_max.top() << std::endl;
	}
	return (0);
}