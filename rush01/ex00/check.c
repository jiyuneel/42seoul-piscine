/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:15:42 by jinwhan           #+#    #+#             */
/*   Updated: 2022/09/04 11:01:29 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	row_check(int depth, int n, int **arr, int *clue)
{
	int	check;
	int	now_value;
	int	index;
	int	count;

	check = clue[2 * n + (depth / n)];
	index = 0;
	count = 1;
	now_value = arr[depth / n][index];
	while (index < n)
	{
		if (now_value < arr[depth / n][index])
		{
			now_value = arr[depth / n][index];
			count++;
		}
		index++;
	}
	if (count == check)
		return (1);
	return (0);
}

int	row_check_reverse(int depth, int n, int **arr, int *clue)
{
	int	check;
	int	now_value;
	int	index;
	int	count;

	check = clue[3 * n + (depth / n)];
	index = n - 1;
	count = 1;
	now_value = arr[depth / n][index];
	while (index >= 0)
	{
		if (now_value < arr[depth / n][index])
		{
			now_value = arr[depth / n][index];
			count++;
		}
		index--;
	}
	if (count == check)
		return (1);
	return (0);
}

int	col_check(int depth, int n, int **arr, int *clue)
{
	int	check;
	int	now_value;
	int	index;
	int	count;

	check = clue[depth % n];
	index = 0;
	count = 1;
	now_value = arr[index][depth % n];
	while (index < n)
	{
		if (now_value < arr[index][depth % n])
		{
			now_value = arr[index][depth % n];
			count++;
		}
		index++;
	}
	if (count == check)
		return (1);
	return (0);
}

int	col_check_reverse(int depth, int n, int **arr, int *clue)
{
	int	check;
	int	now_value;
	int	index;
	int	count;

	check = clue[depth % n + n];
	index = n - 1;
	count = 1;
	now_value = arr[index][depth % n];
	while (index >= 0)
	{
		if (now_value < arr[index][depth % n])
		{
			now_value = arr[index][depth % n];
			count++;
		}
		index--;
	}
	if (count == check)
		return (1);
	return (0);
}

int	wcheck(int depth, int n, int **arr, int *clue)
{
	if ((depth / n == n - 1) && (depth % n == n - 1))
		return (row_check(depth, n, arr, clue)
			&& row_check_reverse(depth, n, arr, clue)
			&& col_check(depth, n, arr, clue)
			&& col_check_reverse(depth, n, arr, clue));
	else if ((depth % n == n - 1))
		return (row_check(depth, n, arr, clue)
			&& row_check_reverse(depth, n, arr, clue));
	else if (depth / n == n - 1)
		return (col_check(depth, n, arr, clue)
			&& col_check_reverse(depth, n, arr, clue));
	return (1);
}
