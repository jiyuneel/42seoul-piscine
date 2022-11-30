/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:05:57 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/07 10:31:13 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_joinlen(int size, char **strs, char *sep)
{
	int	result_len;
	int	i;

	result_len = 0;
	i = 0;
	while (i < size)
	{
		result_len += ft_strlen(strs[i]);
		i++;
	}
	result_len += ft_strlen(sep) * (size - 1);
	return (result_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		result_len;
	int		i;
	char	*result;

	if (size == 0)
		result_len = 0;
	else
		result_len = ft_joinlen(size, strs, sep);
	result = (char *)malloc(sizeof(char) * result_len + 1);
	if (result == 0)
		return (0);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		i++;
		if (i == size)
			break ;
		ft_strcat(result, sep);
	}
	result[result_len] = 0;
	return (result);
}
