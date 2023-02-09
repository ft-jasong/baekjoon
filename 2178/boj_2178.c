#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue
{
	int	x;
	int	y;
	struct s_queue *next;
}Queue;

int		max_row = 0;
int		max_col = 0;
int		distance = 0;
bool	is_found = 0;
char	map[100][100];
Queue	*head = NULL;

void	enqueue(int x, int y)
{
	Queue	*new;
	Queue	*tmp = head;

	new = (Queue *)malloc(sizeof(Queue));
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (!head)
		head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	dequeue(void)
{
	Queue	*tmp = head;

	if (!head)
		return ;
	if (!head->next)
		head = NULL;
	else
		head = head->next;
	free(tmp);
	tmp = NULL;
}

void	bfs()
{

}

int	main(void)
{
	scanf("%d %d", &max_row, &max_col);
	bzero(map, 100 * 100);
	// bzero(visit, 100 * 100);
	for (int i = 0; i < max_row; i++)
		scanf("%s", map[i]);
		
	printf("%d\n", distance);
	return (0);
}