#include <stdio.h>
#include <string.h>

int	sumofPos(int num)
{
	int	sum;

	sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return (sum);
}

int	main(void)
{
	char	num[1000001];
	int		sum;
	int		i;
	int		count;

	scanf("%s", num);
	i = -1;
	sum = 0;
	count = 0;
	if (strlen(num) > 2)
	{
		while (num[++i])
			sum += num[i] - '0';
		count++;
	}
	else
		sum = num[0] - '0';
	while (sum > 9)
	{
		count++;
		sum = sumofPos(sum);
	}
	printf("%d\n", count);
	if (sum % 3 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return (0);
}