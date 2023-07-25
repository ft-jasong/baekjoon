#include <iostream>
#include <stdio.h>

int	main(void)
{
	long long n;

	while (scanf("%lld", &n) != EOF)
	{
		while (n > 18)
			n /= 18;
		if (n <= 9)
			printf("Baekjoon wins.\n");
		else
			printf("Donghyuk wins.\n");
	}
}