/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:26:21 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/27 21:57:28 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nb(int n)
{
	char	c;

	if (n)
	{
		print_nb(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb > 0)
		print_nb(nb);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		write(1, "-", 1);
		print_nb(-nb);
	}
}
