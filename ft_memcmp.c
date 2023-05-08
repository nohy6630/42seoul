/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:53:13 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 08:44:38 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)b1;
	str2 = (char *)b2;
	while (str1[i] == str2[i] && i < len)
		i++;
	if (i >= len)
		return (0);
	else
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
