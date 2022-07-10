#include <stdio.h>

int	getGCD(int a, int b)
{
	int	rest;

	while (b)
	{
		rest = a % b;
		a = b;
		b = rest;
	}
	return (a);
}

int	getAnswer(int m, int n, int x, int y)
{
	int	m_idx;
	int	n_idx;
	int	count;
	int	lcm;
	int	gcd;

	m_idx = 1;
	n_idx = 1;
	count = 1;
	gcd = getGCD(m, n);
	lcm = m * n / gcd;
	if (m == x && n == y)
		return (lcm);
	while (!(m_idx == x && n_idx == y) && count < lcm)
	{
		m_idx++;
		n_idx++;
		count++;
		if (m_idx == m + 1)
			m_idx = 1;
		if (n_idx == n + 1)
			n_idx = 1;
	}
	if (count >= lcm)
		count = -1;
	return (count);
}

int	main(void)
{
	int	m;
	int	n;
	int	x;
	int	y;
	int	test_case;

	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		printf("%d\n", getAnswer(m, n, x, y));
	}
	return (0);
}