/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:20:04 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/26 22:33:45 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	char	c;

	if (n < 10)
	{
		write(1, "0", 1);
		c = '0' + n;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n / 10;
		write(1, &c, 1);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 97)
	{
		j = i + 1;
		while (j <= 99)
		{
			print_num(i);
			write(1, " ", 1);
			print_num(j);
			write(1, ", ", 2);
			j++;
		}
		i++;
	}
	write(1, "98 99", 5);
}
