#include <stdio.h>
#include <math.h>

void	walk(int N, int K, int cur_t, int *time)
{
	if (N == K && cur_t < *time)
	{
		*time = cur_t;
		return ;
	}
	while (cur_t < *time)
	{
		
	}
}

void	teleport(int N, int K, int cur_time, int *time)
{
	N *= 2;
	while (N < K)
	{
		teleport(N, K, cur_time, time);
		walk(N + 1, K, cur_time + 1, time);
		walk(N - 1, K, cur_time + 1, time);
	}
	if (K - N + cur_time < *time)
		*time = K - N + cur_time;
}

int main(void)
{
	int	N, K;
	int	time;

	scanf("%d %d", &N, &K);
	if (K % (2 * N) == 0 || K == N)
	{
		printf("0");
		return (0);
	}
	if (K < N)
	{
		printf("%d", N - K);
		return ;
	}
	time = abs(N - K);
	teleport(N, K, 0, &time);
}