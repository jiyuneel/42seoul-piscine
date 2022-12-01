/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:33:59 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/04 11:34:28 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_split(char *str, int n)
{
	int		i;
	int		cnt;
	char	*result;

	result = (char *)malloc(sizeof(char) * 4 * n + 1);
	if (result == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (i % 2 == 0 && '1' <= str[i] && str[i] <= '0' + n)
		{
			result[cnt] = str[i];
			cnt++;
		}
		i++;
	}
	result[cnt] = 0;
	if (cnt != 4 * n)
	{
		free(result);
		return (0);
	}
	return (result);
}

int	*ft_atoi(char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		arr[i] = str[i] - '0';
		i++;
	}
	return (arr);
}

int	**arr_init(int n)
{
	int	i;
	int	j;
	int	**arr;

	arr = (int **)malloc(sizeof(int *) * n);
	if (arr == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < n)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		if (arr[i] == 0)
			return (0);
		while (j < n)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

int	*clue_init(char *clue_str, int n)
{
	int	*clue;

	clue = (int *)malloc(sizeof(int) * 4 * n);
	if (clue == 0)
		return (0);
	ft_atoi(clue_str, clue);
	return (clue);
}
