/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:05:53 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 08:45:23 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		llen;

	i = 0;
	llen = ft_strlen(little);
	if (!llen)
		return ((char *)big);
	while (big[i] && i + llen <= len)
	{
		j = 0;
		while (big[i + j] && little[j])
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == llen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
