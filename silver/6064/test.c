#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int	getGCD(int a, int b)
{
	int	c;

	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return (a);
}

int main(void)
{
	int		m = 0;
	int		n = 0;
	int		x, y, t_d;
	int		i;
	int		gcd, lcm;

	scanf("%d", &t_d);
	for (i = 0; i < t_d; i++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
	  gcd = getGCD(m, n);
	  lcm = m * n / gcd;
		if (n == y)
			y = y % n;
		int res = x;
		while ((res <= lcm) && res % n != y)
			res += m;
		if (res > lcm)
			printf("-1\n");
		else
			printf("%d", res);
	}

}