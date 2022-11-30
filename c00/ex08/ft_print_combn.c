/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:27:02 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/27 22:00:18 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	push(char *s, char c, int *index)
{
	(*index)++;
	s[*index] = c;
}

char	pop(char *s, int *index)
{
	char	result;

	result = s[*index];
	(*index)--;
	return (result);
}

void	pop_n_times(char *num, int *index, int count)
{
	char	pushchar;
	int		i;

	i = 0;
	while (i++ <= count)
		pushchar = pop(num, index);
	push(num, pushchar + 1, index);
	i = 0;
	while (i++ < count)
		push(num, num[*index] + 1, index);
}

int	count_end(char *num, int n)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (num[i] == '0' + 10 - n + i)
			count++;
		i++;
	}
	return (count);
}

void	ft_print_combn(int n)
{
	char	num[10];
	int		index;

	index = -1;
	push(num, '0', &index);
	while (index + 1 < n)
		push(num, num[index] + 1, &index);
	write(1, num, n);
	write(1, ", ", 2);
	while (1)
	{
		if (count_end(num, n) == n)
			break ;
		if (count_end(num, n))
			pop_n_times(num, &index, count_end(num, n));
		else
			push(num, pop(num, &index) + 1, &index);
		write(1, num, n);
		if (num[0] != '0' + 10 - n)
			write(1, ", ", 2);
	}
}
