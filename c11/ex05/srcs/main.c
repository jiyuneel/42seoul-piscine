/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:34 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/12 09:57:37 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

void	do_operation(char *value1, char *operator, char *value2)
{
	int	num1;
	int	num2;

	if (ft_strlen(operator) != 1)
	{
		write(1, "0\n", 2);
		return ;
	}
	num1 = ft_atoi(value1);
	num2 = ft_atoi(value2);
	if (operator[0] == '+')
		add(num1, num2);
	else if (operator[0] == '-')
		subtract(num1, num2);
	else if (operator[0] == '/')
		divide(num1, num2);
	else if (operator[0] == '*')
		multiply(num1, num2);
	else if (operator[0] == '%')
		modulo(num1, num2);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_operation(argv[1], argv[2], argv[3]);
}
