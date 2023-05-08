/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:54:03 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 08:37:28 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dp;
	char	*sp;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dp = dst;
	sp = (char *)src;
	if (dp > sp)
	{
		i = len - 1;
		while (i-- >= 0)
			dp[len] = sp[len];
	}
	else
	{
		i = 0;
		while (i++ < len)
			dp[len] = sp[len];
	}
	return (dst);
}
/*26행은 겹쳤을때를 대비해 안겹친 부분부터 복사하기 위함*/