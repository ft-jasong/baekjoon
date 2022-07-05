#include <stdio.h>
#include <stdlib.h>

int	getGcd(int m, int n)
{
	int	tmp;
	int	r;

	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	while (n)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return (m);
}

int main(void)
{
	int	M, N, x, y;
	int	T;
	int	gcd, lcm;
	int	mul;
	int	*test;

	scanf("%d", &T);
	test = (int *)calloc(T, sizeof(int));
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		if (M == x && N == y)
			test[i] = x * y;
		else if (M == N)
		{
			if (x == y)
				test[i] = x;
			else
				test[i] = -1;
		}
		else
		{
			gcd = getGcd(M, N);
			lcm = M * N / gcd;
			mul = -1;
			while (M * ++mul <= lcm)
			{
				if (((M * mul + x) % N == y) || ((M * mul + x) % N == 0))
					break;
			}
			if (M * mul > lcm)
				test[i] = -1;
			else
				test[i] = M * mul + x;
		}
	}
	for (int i = 0; i < T; i++)
		printf("%d\n", test[i]);
	free(test);
	return (0);
}