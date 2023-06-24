/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:25:24 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/24 10:50:55 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_prints(char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printp_recur(unsigned long n)
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
	len1 = ft_printp_recur(n / 10);
	len2 = ft_printp_recur(n % 10);
	return (len1 + len2);
}

int	ft_printp(unsigned long adr)
{
	int	len;

	write(1, "0x", 2);
	len = ft_printp_recur(adr);
	return (len + 2);
}
