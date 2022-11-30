/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:13 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/11 19:31:28 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_H
# define EX05_H

# include <unistd.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	add(int value1, int value2);
void	subtract(int value1, int value2);
void	divide(int value1, int value2);
void	multiply(int value1, int value2);
void	modulo(int value1, int value2);

#endif
