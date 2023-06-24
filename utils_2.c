/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:33:49 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/24 11:00:15 by yenoh            ###   ########.fr       */
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
		write(1, &c, 1);
		return (1);
	}
	len1 = ft_printd_recur(n / 10);
	len2 = ft_printd_recur(n % 10);
	return (len1 + len2);
}

int	ft_printd(int n)
{
	int	len;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		len = ft_printd_recur(-n);
		return (len + 1);
	}
	len = ft_printd_recur(n);
	return (len);
}

int	ft_printu_recur(unsigned int n)
{
	char	c;
	int		len1;
	int		len2;

	if (n < 10)
	{
		c = '0' + n;
		write(1, &c, 1);
		return (1);
	}
	len1 = ft_printu_recur(n / 10);
	len2 = ft_printu_recur(n % 10);
	return (len1 + len2);
}

int	ft_printu(unsigned int u)
{
	int	len;

	len = ft_printu_recur(u);
	return (len);
}
