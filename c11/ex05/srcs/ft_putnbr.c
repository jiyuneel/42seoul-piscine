/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:01:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/11 20:00:17 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

void	print_nb(long n)
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
	else
	{
		write(1, "-", 1);
		print_nb(-(long)nb);
	}
}
