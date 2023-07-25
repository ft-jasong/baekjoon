#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void	count_alpha(int alpha[], char *s)
{
	while (*s)
	{
		if (isalpha(*s))
		{
			if (isupper(*s))
				alpha[*s - 'A']++;
			else
				alpha[*s - 'a']++;
		}
		s++;
	}
}

int main(void)
{
	int alpha[26] = {0, };
	char *s;
	int	max_i = 0;
	int	dup;

	s = (char *)malloc(1000001);
	gets(s);
	count_alpha(alpha, s);
	for (int i = 0; i < 26; i++)
	{
		if (max_i < alpha[i])
		{
			max_i = alpha[i];
			dup = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if ((max_i == alpha[i]) && (dup != i))
		{
			printf("?");
			return (0);
		}
	}
	printf("%c", 'A' + dup);
	return (0);
}