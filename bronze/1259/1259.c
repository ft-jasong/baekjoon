#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[6];
	int		len;
	int		ispellin;

	while (1)
	{	
		scanf("%s", str);
		if (!strcmp(str, "0"))
			break ;
		ispellin = TRUE;
		len = strlen(str);
		for (int i = 0; i < len / 2; i++)
		{
			if (str[i] != str[len - 1 - i])
			{
				ispellin = FALSE;
				break ;
			}
		}
		if (ispellin)
			printf("yes\n");
		else
			printf("no\n");
	}
}