#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void mix(priority_queue<int, vector<int>, greater<int> > &pq, int &answer)
{
	int	min;
	int	min_sec;

	if (pq.size() == 1)
	{
		answer = -1;
		return ;
	}
	min = pq.top();
	pq.pop();
	min_sec = pq.top();
	pq.pop();
	pq.push(min + min_sec * 2);
	answer++;
}

void hotter(priority_queue<int, vector<int>, greater<int> > &pq, int &answer, int K)
{
	int	min;
	int	min_sec;

	while (pq.top() < K && answer >= 0)
		mix(pq, answer);
}

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int> >	pq;

	for (auto i : scoville)
		pq.push(i);
	hotter(pq, answer, K);
	return answer;
}

int	main(void)
{
	vector<int>	test{1, 2};

	cout << solution(test, 7) << '\n';
	return (0);
}