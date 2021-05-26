#include <stdio.h>
#include <stdlib.h>

void get_parm(int *num, int *won)
{
	scanf("%d %d", num, won);
}

int main(void)
{
	int	n;
	int	won;
	int	*money;
	int	count = 0;

	get_parm(&n, &won);
	money = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", money + i);
	while (won && n-- > 0)
	{
		if (won / money[n] > 0)
		{
			count += won / money[n];
			won = won - money[n] * (won / money[n]); 
		}
	}
	free(money);
	printf("%d", count);
	return (0);	
}