/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:48:45 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/08/30 13:19:09 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cnt;

	cnt = 0;
	if (size != 0)
	{
		while (src[cnt] && cnt < size - 1)
		{
			dest[cnt] = src[cnt];
			cnt++;
		}
		dest[cnt] = '\0';
	}
	while (src[cnt])
		cnt++;
	return (cnt);
}
