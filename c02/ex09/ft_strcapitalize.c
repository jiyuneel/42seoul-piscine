/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:35:11 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/28 22:36:26 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_letter(char c)
{
	if (is_lowercase(c) || is_uppercase(c) || is_number(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	while (str[i])
	{
		first = 0;
		if (i == 0 || !is_letter(str[i - 1]))
			first = 1;
		if (first && is_lowercase(str[i]))
			str[i] = str[i] - 'a' + 'A';
		if (!first && is_uppercase(str[i]))
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}
