#include <stdlib.h>
#include <stdio.h>

void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	quick_sort(int n[], int left, int right)
{
	int		l_hold;
	int		r_hold;
	int		pivot;

	pivot = n[left];
	r_hold = right;
	l_hold = left;
	while (left < right)
	{
		if (left == l_hold)
			left++;
		while (left <= right && n[left] <= pivot)
			left++;
		while (left <= right && n[right] > pivot)
			right--;
		if (left < right)
			swap(&n[left], &n[right]);
	}
	if (l_hold < r_hold)
	{
		swap(&n[l_hold], &n[right]);
		quick_sort(n, l_hold, right - 1);
		quick_sort(n, right + 1, r_hold);
	}
}

int		main(void)
{
	int		n;
	int		*num;

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	for (int i = 0;i < n; i++)
		scanf("%d", num + i);
	quick_sort(num, 0, n - 1);
	for(int i = 0; i < n; i++)
	{
		printf("%d", num[i]);
		if (i != n - 1)
			printf("\n");
	}
	free(num);
	return (0);
}
