
#include "e_q.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_safe_col(char **tab, int x, int N)
{
	int		i;

	i = -1;
	while(++i < N)
		if (tab[i][x])
			return (0);
	return (1);
}

int		is_safe_diag(char **tab, int y, int x, int N)
{
	int x1 = x;
	int y1 = y;
	
	while (x && y)
	{
		x--;
		y--;
	}
	while (x < N && y < N)
	{
		if (tab[y][x])
			return (0);
		x++;
		y++;
	}
	while (x1 && y1 < N - 1)
	{
		x1--;
		y1++;
	}
	while (x1 < N && y1 >= 0)
	{
		if (tab[y1][x1])
			return (0);
		x1++;
		y1--;
	}
	
	return (1);
}

int		is_safe_place(char **tab, int y, int x, int N)
{
	if (is_safe_col(tab, x, N))
		if (is_safe_diag(tab, y, x, N))
			return (1);
	return (0);
}

void	ft_print(char **tab, int N)
{
	int		x;
	int		y;

	y = -1;
	while (++y < N)
	{
		x = -1;
		while (++x < N)
			if (tab[y][x])
				printf("%d ", x + 1);
	}
	printf("\n");
}

int		ft_eight_queens(char ***tab, int y, int *count, int N)
{
	int		x;

	x = 0;
	if (y == N)
		return (0);
	while (x < N)
	{
		if (is_safe_place(*tab, y, x, N))
		{
			(*tab)[y][x] = 1;
			if (y == N - 1)
			{
				// ft_print(*tab, N);
				(*count)++;
			}
			if (ft_eight_queens(tab, y + 1, count, N))
				return (1);
			(*tab)[y][x] = 0;
		}
		x++;
	}
	return (0);
}

void	ft_eight_queens_puzzle_2(int N)
{
	char	**tab;
	int		i;
	int		j;
	int		count;
	
	if(!(tab = (char **)malloc(sizeof(char *) * N)))
		return ;
	i = -1;
	while (++i < N)
	{
		tab[i] = (char *)malloc(sizeof(char) * N);
		j = -1;
		while(++j < N)
			tab[i][j] = 0;
	}
	count = 0;
	ft_eight_queens(&tab, 0, &count, N);
	// printf("\n--------------------------------------------\n\n");
	printf("Count of all posible solutions: %d\n\n", count);
}

int main()
{
	ft_eight_queens_puzzle_2(13);
	return (0);
}
