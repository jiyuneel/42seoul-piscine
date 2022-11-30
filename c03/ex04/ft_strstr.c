/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:10:53 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/31 14:18:15 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j])
			{
				if (to_find[j] == str[i + j])
					j++;
				else
					break ;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
