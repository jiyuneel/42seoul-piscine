/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:28:21 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/07 10:17:06 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	is_valid_base(char *base);
int	ft_atoi_base(char *str, char *base);

void	char_cat(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	str[i++] = c;
	str[i] = '\0';
}

void	nbr_base_result(long nbr, char *base, char *result)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr)
	{
		nbr_base_result(nbr / base_len, base, result);
		char_cat(base[nbr % base_len], result);
	}
}

void	ft_putnbr_base(int nbr, char *base, char *result)
{
	if (nbr > 0)
		nbr_base_result(nbr, base, result);
	else if (nbr == 0)
		char_cat(base[0], result);
	else
	{
		char_cat('-', result);
		nbr_base_result(-(long)nbr, base, result);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;
	int		result_len;
	int		n;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	result_len = 0;
	n = num;
	if (n <= 0)
	{
		result_len++;
		n *= -1;
	}
	while (n)
	{
		n /= ft_strlen(base_to);
		result_len++;
	}
	result = (char *)malloc(sizeof(char) * result_len + 1);
	result[0] = '\0';
	ft_putnbr_base(num, base_to, result);
	return (result);
}
