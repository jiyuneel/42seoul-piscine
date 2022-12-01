/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:28:20 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/28 17:15:14 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char left, char middle, char right);

void	rush(int x, int y)
{
	int	cnt;

	if (x <= 0 || y <= 0)
		return ;
	cnt = 1;
	print_line(x, 'A', 'B', 'A');
	while (cnt <= y - 2)
	{
		print_line(x, 'B', ' ', 'B');
		cnt++;
	}
	if (y >= 2)
		print_line(x, 'C', 'B', 'C');
}

void	print_line(int x, char left, char middle, char right)
{
	int	cnt;

	cnt = 1;
	ft_putchar(left);
	while (cnt <= x - 2)
	{
		ft_putchar(middle);
		cnt++;
	}
	if (x >= 2)
		ft_putchar(right);
	ft_putchar('\n');
}
