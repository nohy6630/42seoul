/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:07:06 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 08:07:15 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	s;
	int	e;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	s = 0;
	while (s1[s] && ft_strchr(set, s1[s]) != NULL)
		s++;
	e = ft_strlen(s1) - 1;
	while (e >= 0 && ft_strchr(set, s1[e]) != NULL)
		e--;
	if (!s1[s])
		return (ft_strdup(""));
	return (ft_substr(s1, s, e - s + 1));
}
