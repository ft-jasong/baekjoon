/*
** not finished !!
*/
#include <stdio.h>
#include <stdlib.h>

int		**makearr(int n)
{
	int		i;
	int		**arr;

	i = -1;
	arr = (int **)calloc(n, sizeof(int *));
	while (++i < n)
		arr[i] = (int **)calloc(2, sizeof(int));
	return (arr);
}

void	getwv(int **arr, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
}

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
	int		k;
	int		**arr;

	scanf("%d %d", &n, &k);
	arr = makearr(n);
	getwv(arr, n);
}