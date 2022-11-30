/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:03 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/28 22:06:06 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lowercase(str[i]))
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
	return (str);
}
