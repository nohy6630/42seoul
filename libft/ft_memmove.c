/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:54:03 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 13:46:49 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	setmem(char *dp, char *sp, size_t len)
{
	int	i;

	if (dp > sp)
	{
		i = len - 1;
		while (i >= 0)
		{
			dp[i] = sp[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			dp[i] = sp[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	setmem(dst, (char *)src, len);
	return (dst);
}
