/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:42:46 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/15 01:54:05 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_long_atoi(const char *nptr, int *check)
{
	long		i;
	long long	n;

	i = 0;
	n = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		i++;
		if (!nptr[i])
			*check = 1;
	}
	if (nptr[i] && nptr[i] == '0' && nptr[i + 1])
	{
		*check = 1;
		return (0);
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		n = n * 10 + (nptr[i++] - '0');
	if (nptr[0] == '-')
		n *= -1;
	if (n > 2147483647 || n < -2147483648)
		*check = 1;
	return (n);
}
