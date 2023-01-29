#include <stdio.h>

int	main(void)
{
	int	boonja;
	int	boonmo;
	int	num;
	int	answer;
	int	rest;

	scanf("%d %d %d", &boonja, &boonmo, &num);
	rest = boonja % boonmo;
	for (int i = 0; i < num; i++)
	{
		rest *= 10;
		answer = rest / boonmo;
		rest %= boonmo;
	}
	printf("%d\n", answer);
	return (0);
}