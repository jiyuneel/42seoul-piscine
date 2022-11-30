/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:59:59 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/11 18:03:17 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	minus;

	result = 0;
	minus = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (minus * result);
}
