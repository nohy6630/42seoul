/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:59:52 by yenoh             #+#    #+#             */
/*   Updated: 2023/05/09 08:00:21 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_str(const char *str, char c, char **save)
{
	int	size;
	int	i;
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	size = len + 1;
	*save = malloc(sizeof(char) * size);
	i = 0;
	while (str[i] && str[i] != c)
	{
		(*save)[i] = str[i];
		i++;
	}
	(*save)[size - 1] = 0;
}

int	arr_size(const char *str, char c)
{
	int	i;
	int	size;

	size = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char	**ft_split(const char *s, char c)
{
	int		size;
	char	**ret;
	int		idx;

	idx = 0;
	size = arr_size(s, c);
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			set_str(s, c, &ret[idx++]);
		while (*s && (*s) != c)
			s++;
	}
	ret[size - 1] = 0;
	return (ret);
}
