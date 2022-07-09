#include <stdio.h>
int main(void)
{
	int		a;
	int		b;
	double	res;

	scanf("%d %d", &a, &b);
	 res = (double)a / (double)b;
	printf("%.9f", res);
	return (0);
}