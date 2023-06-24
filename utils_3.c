/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:56:40 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/24 10:37:35 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx_recur(unsigned int n, char f)
{
	int		len1;
	int		len2;
	char	*alpha;

	if (n < 16)
	{
		if (f == 'x')
			alpha = "0123456789abcdef";
		else
			alpha = "0123456789ABCDEF";
		write(1, &alpha[n], 1);
		return (1);
	}
	len1 = ft_printx_recur(n / 16, f);
	len2 = ft_printx_recur(n % 16, f);
	return (len1 + len2);
}

int	ft_printx(unsigned int n, char f)
{
	int	len;

	len = ft_printx_recur(n, f);
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
