/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:52:51 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/29 21:54:20 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(long long int addr)
{
	char	memory[16];
	int		i;

	i = 0;
	while (i < 16)
		memory[i++] = '0';
	i = 15;
	while (addr)
	{
		memory[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, memory, 16);
	write(1, ": ", 2);
}

void	print_hex_cnts(unsigned char *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[*(addr + i) / 16], 1);
		write(1, &"0123456789abcdef"[*(addr + i) % 16], 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	if (size < 16)
	{
		while (i < 16)
		{
			write(1, "  ", 2);
			if (i % 2)
				write(1, " ", 1);
			i++;
		}
	}
}

void	print_lttr_cnts(unsigned char *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (32 <= addr[i] && addr[i] <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size / 16)
	{
		print_addr((long long int) addr + i * 16);
		print_hex_cnts((unsigned char *) addr + i * 16, 16);
		print_lttr_cnts((unsigned char *) addr + i * 16, 16);
		i++;
	}
	if (size % 16)
	{
		print_addr((long long int) addr + i * 16);
		print_hex_cnts((unsigned char *) addr + i * 16, size % 16);
		print_lttr_cnts((unsigned char *) addr + i * 16, size % 16);
	}
	return (addr);
}
