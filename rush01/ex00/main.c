/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyu <seonghyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:12:15 by seonghyu          #+#    #+#             */
/*   Updated: 2022/09/04 16:33:42 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_split(char *str, int n);
int		*ft_atoi(char *str, int *arr);
int		**arr_init(int n);
int		*clue_init(char *clue_str, int n);
int		recur(int **arr, int depth, int n, int *clue);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	print_arr(int **arr, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = arr[i][j] + '0';
			write (1, &c, 1);
			if (j == n - 1)
				break ;
			write (1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		n;
	int		*clue;
	char	*clue_str;
	int		**arr;

	if (argc == 2)
	{
		n = (ft_strlen(argv[1]) + 1) / 8;
		clue_str = ft_split(argv[1], n);
		if (ft_strlen(argv[1]) == (8 * n - 1) && clue_str)
		{
			clue = clue_init(clue_str, n);
			free(clue_str);
			arr = arr_init(n);
			if (recur(arr, 0, n, clue))
				print_arr(arr, n);
			else
				write(2, "Error\n", 6);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
}
