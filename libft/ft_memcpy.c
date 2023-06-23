/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:53:24 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 13:50:51 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*dp;
	char	*sp;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dp = dst;
	sp = (char *)src;
	i = 0;
	while (i < len)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dst);
}
