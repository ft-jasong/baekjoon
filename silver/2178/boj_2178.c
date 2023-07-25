#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue
{
	int	x;
	int	y;
	int	distance;
	struct s_queue *next;
}Queue;

int		max_row = 0;
int		max_col = 0;
int		answer = 0;
bool	is_found = 0;
char	map[100][101];
char	visit[100][101];
Queue	*head = NULL;
Queue	*rear = NULL;

void	enqueue(int x, int y, int d)
{
	Queue	*new;

	new = (Queue *)malloc(sizeof(Queue));
	new->x = x;
	new->y = y;
	new->distance = d;
	new->next = NULL;
	if (!head)
	{
		head = new;
		rear = new;
	}
	else
	{
		rear->next = new;
		rear = new;
	}
}

void	dequeue(void)
{
	Queue	*tmp = head;

	if (!head)
		return ;
	if (!head->next)
	{
		head = NULL;
		rear = NULL;
	}
	else
		head = head->next;
	free(tmp);
	tmp = NULL;
}

void	bfs()
{
	while (head)
	{
		int	x = head->x;
		int y = head->y;
		int d = head->distance;

		visit[y][x] = 1;
		dequeue();
		if (x == max_col - 1 && y == max_row - 1)
		{
			answer = d;
			break ;
		}
		if (x >= 0  && !visit[y][x - 1] && map[y][x - 1] == '1') // 왼쪽
			enqueue(x - 1, y, d + 1);
		if (x + 1 < max_col && !visit[y][x + 1] && map[y][x + 1] == '1') // 오른쪽
			enqueue(x + 1, y, d + 1);
		if (y >= 0 && !visit[y - 1][x] && map[y - 1][x] == '1') // 위
			enqueue(x, y - 1, d + 1);
		if (y + 1 >= 0 && !visit[y + 1][x] && map[y + 1][x] == '1') // 아래
			enqueue(x, y + 1, d + 1);
	}
}

int	main(void)
{
	scanf("%d %d", &max_row, &max_col);
	bzero(map, 100 * 101);
	bzero(visit, 100 * 101);
	for (int i = 0; i < max_row; i++)
		scanf("%s", map[i]);
	enqueue(0, 0, 1);
	bfs();
	printf("%d\n", answer);
	return (0);
}