/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:19:26 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/28 17:29:11 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *num)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (num[i] != '\0')
	{
		if (('0' <= num[i]) && (num[i] <= '9'))
			result = result * 10 + num[i++] - '0';
		else
			break ;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
