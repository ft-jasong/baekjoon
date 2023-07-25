#include <stdio.h>

int	main(void)
{
	double n;

	while (scanf("%lf", &n) != EOF)
	{
		while (n > 18)
			n /= 18;
		if (n <= 9)
			printf("Baekjoon wins.\n");
		else	
			printf("Donghyuk wins.\n");
	}
	return (0);
}