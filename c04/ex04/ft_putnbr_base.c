/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:30:51 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/31 20:31:20 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	print_nbr_base(int nbr, char *base, int base_len)
{
	if (nbr)
	{
		print_nbr_base(nbr / base_len, base, base_len);
		write(1, &base[nbr % base_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (!is_valid_base(base))
		return ;
	if (nbr > 0)
		print_nbr_base(nbr, base, base_len);
	else if (nbr == 0)
		write(1, &base[0], 1);
	else
	{
		write(1, "-", 1);
		print_nbr_base(-(nbr / base_len), base, base_len);
		write(1, &base[-(nbr % base_len)], 1);
	}
}
