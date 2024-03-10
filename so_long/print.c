/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:08 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 23:37:40 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printd_recur(int n)
{
	char	c;
	int		len1;
	int		len2;

	if (n < 10)
	{
		c = '0' + n;
		return (write(1, &c, 1));
	}
	len1 = ft_printd_recur(n / 10);
	if (len1 == -1)
		return (-1);
	len2 = ft_printd_recur(n % 10);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_printd(int n)
{
	int	len;
	int	chk;

	if (n == -2147483648)
		return (write(1, "-2147483648\n", 12));
	if (n < 0)
	{
		len = write(1, "-", 1);
		if (len == -1)
			return (-1);
		len = ft_printd_recur(-n);
		chk = write(1, "\n", 1);
		if (len == -1 || chk == -1)
			return (-1);
		return (len + 1);
	}
	len = ft_printd_recur(n);
	chk = write(1, "\n", 1);
	if (len == -1 || chk == -1)
		return (-1);
	return (len);
}
