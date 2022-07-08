#include <iostream>
#include <vector>

using namespace std;

int	getGCD(int a, int b)
{
	int	r;

	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int	getAnswer(int m, int n, int x, int y)
{
	int	gcd, lcm;
	int	iterx;
	int	itery;

	gcd = getGCD(m, n);
	lcm = m * n / gcd;
	if (lcm == x * y && x == m && y == n)
		return (lcm);
	iterx = -1;
	itery = 0;
	while (++iterx * m + x <= lcm)
	{
		while (itery * n + y <= iterx * m + x)
		{
			if (iterx * m + x == itery * n + y)
				return (iterx * m + x);
			itery++;
		}
	}
	return (-1);
}

int	main(void)
{
	int	test_case;
	int	m, n;
	int	x, y;
	vector<int>	ans;

	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> m >> n >> x >> y;
		ans.push_back(getAnswer(m, n, x, y));
	}
	for (vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << endl;
	return (0);
}