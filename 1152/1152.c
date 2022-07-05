#include <stdio.h>

int main(void)
{
	char s[1000001];
	int	n = 0;
	int	flag = 1;
	int	i = 0;

	scanf("%[^\n]", s);
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			flag = 1;
		else
		{
			if (flag)
			{
				n++;
				flag = 0;
			}
		}
		i++;
	}
	printf("%d", n);
	return (0);
}
