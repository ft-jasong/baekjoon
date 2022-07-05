#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

static int	get_size(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;

	size = get_size(n);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (n < 0)
		ret[0] = '-';
	while (size-- && n)
	{
		if (n > 0)
			ret[size] = '0' + n % 10;
		else
			ret[size] = '0' - n % 10;
		n /= 10;
	}
	return (ret);
}

int	is_one_five(char *s)
{
	while (*s)
	{
		if (*s != '1' && *s != '5')
			return (0);
		s++;
	}
	return (1);
}

int main(void)
{
	char *s;
	int	n;
	int	i = 0;

	while (1)
	{
		if (i < 0)
			break;
		n = ++i * 15;
		s = ft_itoa(n);
		if (n & 0x01 && is_one_five(s))
		{
			if (n % 15 == 0)
				printf("%d\n", n);
		}
		free(s);
	}
	return (0);
}