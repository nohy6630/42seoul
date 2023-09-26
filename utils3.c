/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:51:57 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/27 08:22:55 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_str_2(const char *str, char c, char **save)
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

int	arr_size_2(const char *str, char c)
{
	int		i;
	int		size;
	char	tmp;

	size = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\'' || str[i] == '\"')
		{
			tmp = str[i];
			size++;
			i++;
			while (str[i] && str[i] != tmp)
				i++;
			i++;
		}
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

const char	*chk_quotes(const char *s, char **save)
{
	char	c;

	c = *s;
	s++;
	set_str_2(s, c, save);
	while (*s && (*s) != c)
		s++;
	return (s);
}

char	**ft_split_2(const char *s, char c)
{
	int		size;
	char	**ret;
	int		idx;

	idx = 0;
	size = arr_size_2(s, c);
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\'' || *s == '\"')
			s = chk_quotes(s, &ret[idx++]);
		else if (*s)
		{
			set_str_2(s, c, &ret[idx++]);
			while (*s && (*s) != c)
				s++;
		}
	}
	ret[size - 1] = 0;
	return (ret);
}
