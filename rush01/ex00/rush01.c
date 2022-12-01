/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:20:54 by seonghyu          #+#    #+#             */
/*   Updated: 2022/09/04 11:03:00 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wcheck(int depth, int n, int **arr, int *clue);

int	check(int depth, int i, int **arr, int n)
{
	int	k;

	k = 0;
	while (k < depth / n)
	{
		if (i == arr[k][depth % n])
			return (0);
		k++;
	}
	k = 0;
	while (k < depth % n)
	{
		if (i == arr[depth / n][k])
			return (0);
		k++;
	}
	return (1);
}

int	shor(int depth, int n, int **arr, int *clue)
{
	if (!wcheck(depth, n, arr, clue))
	{
		arr[depth / n][depth % n] = 0;
		return (0);
	}
	return (1);
}

int	recur(int **arr, int depth, int n, int *clue)
{
	int	i;

	i = 0;
	if (depth == n * n)
		return (1);
	while (++i < n + 1)
	{
		if (check(depth, i, arr, n))
		{
			arr[depth / n][depth % n] = i;
			if (!shor(depth, n, arr, clue))
				continue ;
			if (!recur(arr, depth + 1, n, clue))
			{
				arr[depth / n][depth % n] = 0;
				continue ;
			}
			else
				return (1);
		}
	}
	return (0);
}
