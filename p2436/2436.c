#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

ull	getGCD(ull a, ull b)
{
	ull r;

	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int	main(void)
{
	ull	gcd, lcm;
	ull	sr;

	scanf("%llu %llu", &gcd, &lcm);
	sr = (ull)sqrtl(lcm / gcd);
	while (1)
	{
		if (((lcm / gcd) % sr == 0) && (getGCD(lcm / gcd / sr, sr) == 1))
			break ;
		sr++;
	}
	if (lcm / gcd / sr > sr)
		printf("%llu %llu\n", sr * gcd, lcm / sr);
	else
		printf("%llu %llu\n", lcm / sr, sr * gcd);
	return (0);
}