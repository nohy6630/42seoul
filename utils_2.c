/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:33:49 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/27 16:11:43 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len = write(1, "-", 1);
		if (len == -1)
			return (-1);
		len = ft_printd_recur(-n);
		if (len == -1)
			return (-1);
		return (len + 1);
	}
	return (ft_printd_recur(n));
}

int	ft_printu_recur(unsigned int n)
{
	char	c;
	int		len1;
	int		len2;

	if (n < 10)
	{
		c = '0' + n;
		return (write(1, &c, 1));
	}
	len1 = ft_printu_recur(n / 10);
	if (len1 == -1)
		return (-1);
	len2 = ft_printu_recur(n % 10);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_printu(unsigned int u)
{
	return (ft_printu_recur(u));
}
