/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:12:32 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 12:41:06 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bsq(char *map_str)
{
	t_map	info;
	t_max	data;
	char	**map_arr;
	int		**map_int;

	if (map_info(map_str, &info) == 0)
		return (print_err());
	map_arr = parse_info(map_str, info);
	free(map_str);
	if (map_arr == 0)
		return (print_err());
	map_int = map_init(info, map_arr);
	free_char(map_arr, info.line);
	if (map_int == 0)
		return (print_err());
	find_square(map_int, info, &data);
	print_result(map_int, info, data);
	free_int(map_int, info.line);
	return (1);
}

char	*get_input(void)
{
	int		i;
	char	c;
	char	*arr;
	int		arr_size;

	arr_size = 10000;
	arr = (char *)malloc(sizeof(char) * (arr_size + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (i >= arr_size)
			ft_realloc(&arr, arr_size);
		arr[i] = c;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*map_str;

	if (argc == 1)
	{
		map_str = get_input();
		bsq(map_str);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map_str = read_file(argv[i]);
			if (map_str == 0)
				write(2, "map error\n", 10);
			else
				bsq(map_str);
			i++;
		}
	}
}
