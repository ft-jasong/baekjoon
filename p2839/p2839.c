#include <stdio.h>

int main(void)
{
	int n;
	int rest;

	scanf("%d", &n);
	if (n == 4 || n == 7)
	{
		printf("-1");
		return (0);
	}
	rest = n % 5;
	switch (rest)
	{
	case 0: printf("%d", n / 5);
		break;
	case 1: printf("%d", (n - 6) / 5 + 2);
		break;
	case 2: printf("%d", (n - 12) / 5 + 4);
		break;
	case 3: printf("%d", (n - 3) / 5 + 1);
		break;
	case 4: printf("%d", (n - 9) / 5 + 3);
		break ;
	}
	return (0);
}
