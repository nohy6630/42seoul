/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:25:24 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/27 15:37:06 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c)
{
	return (write(1, &c, 1));
}

int	ft_prints(char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_printp_recur(unsigned long n)
{
	int		len1;
	int		len2;
	char	*alpha;

	if (n < 16)
	{
		alpha = "0123456789abcdef";
		return (write(1, &alpha[n], 1));
	}
	len1 = ft_printp_recur(n / 16);
	len2 = ft_printp_recur(n % 16);
	if (len1 == -1 || len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_printp(unsigned long adr)
{
	int	len;

	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	len = ft_printp_recur(adr);
	if (len == -1)
		return (-1);
	return (len + 2);
}
