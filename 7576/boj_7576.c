#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_queue
{
	int				x;
	int				y;
	int				depth;
	struct s_queue	*next;
}Queue;

Queue	*head = NULL;
Queue	*rear = NULL;
int		row;
int		col;
int		max_depth = 0;
int 	box[1000][1000];

void	enqueue(int x, int y, int depth)
{
	Queue	*new;

	new = calloc(1, sizeof(Queue));
	new->x = x;
	new->y = y;
	new->depth = depth;
	new->next = NULL;
	box[y][x] = 1;
	if (!head)
	{
		head = new;
		rear = new;
	}
	else
	{
		rear->next = new;
		rear = rear->next;
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
}


void	bfs()
{
	int	x;
	int	y;
	int	depth;

	while (head)
	{
		x = head->x;
		y = head->y;
		depth = head->depth;
		if (max_depth < depth)
			max_depth = depth;
		if (x - 1 >= 0 && !box[y][x - 1]) // left
			enqueue(x - 1, y, depth + 1);
		if (x + 1 < col && !box[y][x + 1]) // right
			enqueue(x + 1, y, depth + 1);
		if (y - 1 >= 0 && !box[y - 1][x]) // up
			enqueue(x, y - 1, depth + 1);
		if (y + 1 < row && !box[y + 1][x]) // down
			enqueue(x, y + 1, depth + 1);
		dequeue();
	}
}

int	is_all_riped(void)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if (!box[y][x])
				return (0);
		}
	}
	return (1);
}

int	main(void)
{

	scanf("%d %d", &col, &row);
	bzero(box, sizeof(box));
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			scanf("%d", &box[y][x]);
			if (box[y][x] == 1)
				enqueue(x, y, 0);
		}
	}
	bfs();
	if (is_all_riped())
		printf("%d\n", max_depth);
	else
		printf("-1\n");
	return (0);
}