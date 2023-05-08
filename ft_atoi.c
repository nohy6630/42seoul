/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:43:58 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 07:44:55 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || \
	c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	ret;

	i = 0;
	while (ft_iswhitespace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	ret = 0;
	while (nptr[i] && ft_isalpha(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	return (ret * sign);
}
