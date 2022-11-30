/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:33:05 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/06 22:30:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			count++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;
	int		arr_index;

	arr = (char **)malloc(sizeof(char *) * count_word(str, charset) + 1);
	arr_index = 0;
	i = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			j = i;
			while (str[j] && !is_charset(str[j], charset))
				j++;
			arr[arr_index] = (char *)malloc(sizeof(char) * (j - i) + 1);
			ft_strncpy(arr[arr_index], &str[i], j - i);
			arr_index++;
			i = j;
		}
		i++;
	}
	arr[arr_index] = 0;
	return (arr);
}
