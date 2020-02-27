/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eightqueens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kk <kk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:15:45 by kk                #+#    #+#             */
/*   Updated: 2020/02/27 22:30:30 by kk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_q.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_safe_col(char **tab, int x)
{
	int		i;

	i = -1;
	while(++i < 8)
		if (tab[i][x])
			return (0);
	return (1);
}

int		is_safe_diag(char **tab, int y, int x)
{
	int x1 = x;
	int y1 = y;
	
	while (x && y)
	{
		x--;
		y--;
	}
	while (x < 8 && y < 8)
	{
		if (tab[y][x])
			return (0);
		x++;
		y++;
	}
	while (x1 && y1 < 7)
	{
		x1--;
		y1++;
	}
	while (x1 < 8 && y1 >= 0)
	{
		if (tab[y1][x1])
			return (0);
		x1++;
		y1--;
	}
	
	return (1);
}

int		is_safe_place(char **tab, int y, int x)
{
	if (is_safe_col(tab, x))
		if (is_safe_diag(tab, y, x))
			return (1);
	return (0);
}

void	ft_print(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 8)
	{
		x = -1;
		while (++x < 8)
			if (tab[y][x])
				ft_putchar(x + 1 + '0');
	}
	ft_putchar('\n');
}

int		ft_eight_queens(char ***tab, int y, int *count)
{
	int		x;

	x = 0;
	if (y == 8)
		return (0);
	while (x < 8)
	{
		if (is_safe_place(*tab, y, x))
		{
			(*tab)[y][x] = 1;
			if (y == 7)
			{
				ft_print(*tab);
				(*count)++;
			}
			if (ft_eight_queens(tab, y + 1, count))
				return (1);
			(*tab)[y][x] = 0;
		}
		x++;
	}
	return (0);
}

void	ft_eight_queens_puzzle_2()
{
	char	**tab;
	int		i;
	int		j;
	int		count;
	
	if(!(tab = (char **)malloc(sizeof(char *) * 8)))
		return ;
	i = -1;
	while (++i < 8)
	{
		tab[i] = (char *)malloc(sizeof(char) * 8);
		j = -1;
		while(++j < 8)
			tab[i][j] = 0;
	}
	count = 0;
	ft_eight_queens(&tab, 0, &count);
	printf("\n--------------------------------------------\n\n");
	printf("Count of all posible solutions: %d\n\n", count);
}

int main()
{
	ft_eight_queens_puzzle_2();
	return (0);
}
