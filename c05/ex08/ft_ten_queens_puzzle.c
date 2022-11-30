/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:35:15 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/06 13:14:00 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int x, int y, int *board)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y)
			return (0);
		if (board[i] - y == i - x || board[i] - y == x - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	pos_queens(int x, int *board, int *count)
{
	int	y;

	if (x == 10)
	{
		(*count)++;
		print_board(board);
		return ;
	}
	y = 0;
	while (y < 10)
	{
		if (is_valid(x, y, board))
		{
			board[x] = y;
			pos_queens(x + 1, board, count);
		}
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	pos_queens(0, board, &count);
	return (count);
}
