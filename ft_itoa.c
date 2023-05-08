/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:47:05 by jinhokim          #+#    #+#             */
/*   Updated: 2023/05/09 07:50:57 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	set_res(int n, char *res, int len, int i)
{
	while (len > i)
	{
		len--;
		if (n < 0)
			res[len] = n % 10 * (-1) + '0';
		else
			res[len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;

	len = get_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
	}
	else
		i = 0;
	set_res(n, res, len, i);
	return (res);
}
