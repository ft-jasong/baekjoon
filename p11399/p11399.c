#include <stdio.h>
#include <stdlib.h>

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

void 	get_time(int *time, int n)
{
	int		i;

	i = -1;
	while(++i < n)
		scanf("%d", time + i);
}

int		get_sum(int *arr, int n)
{
	int		sum;
	int		i;

	sum = 0;
	i = -1;
	while (++i < n)
		sum += (n - i) * arr[i];
	return (sum);
}

int		main(void)
{
	int		n;
	int		*time;
	int		res;

	scanf("%d", &n);
	time = (int *)calloc(n, sizeof(int));
	get_time(time, n);
	quick_sort(time, 0, n - 1);
	res = get_sum(time, n);
	free(time);
	printf("%d", res);
	return (0);
}