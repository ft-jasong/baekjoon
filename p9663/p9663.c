#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		is_valid_col(int *row, int depth, int col)
{
	int		i;
	
	i = -1;
	while (++i < depth)
	{
		if (row[i] == col || abs(row[i] - col) == abs(i - depth))
			return (0);
	}
	return (1);
}

void	nqueens(int *row, int n, int depth, int *count)
{
	int		col;

	col = 0;

	if (depth == n)
		(*count)++;
	while (depth < n)
	{
		if (col < n)
		{
			if (is_valid_col(row, depth, col))
			{
				row[depth] = col;
				nqueens(row, n, depth + 1, count);
			}
			col++;
		}
		else
			break;
	}
}

int solution(int n)
{
	int answer = 0;
	int *row;

	row = (int *)malloc(sizeof(int) * n);
	nqueens(row, n, 0, &answer);
	free(row);
	return answer;
}

int main(void)
{
    int    n;
    
    scanf("%d", &n);
    printf("%d", solution(n));
    return (0);
}