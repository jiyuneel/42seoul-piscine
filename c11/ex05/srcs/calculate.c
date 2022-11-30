/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:44 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/12 09:57:07 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

void	add(int value1, int value2)
{
	ft_putnbr(value1 + value2);
}

void	subtract(int value1, int value2)
{
	ft_putnbr(value1 - value2);
}

void	divide(int value1, int value2)
{
	if (value2 == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(value1 / value2);
}

void	multiply(int value1, int value2)
{
	ft_putnbr(value1 * value2);
}

void	modulo(int value1, int value2)
{
	if (value2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(value1 % value2);
}
