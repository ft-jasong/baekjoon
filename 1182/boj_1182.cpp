#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0;
int	dest;

void backtrack(vector<int>& v, int depth, int _sum, int count)
{
	if (depth >= (int)v.size())
	{
		if (count && (_sum == dest))
			++answer;
		return ;
	}
	else
	{
		backtrack(v, depth + 1, _sum + v[depth], count + 1);
		backtrack(v, depth + 1, _sum, count);
	}
}

int	main(void)
{
	int	N;
	cin >> N >> dest;
	vector<int>	v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	backtrack(v, 0, 0, 0);
	cout << answer << endl;
}