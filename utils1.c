/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:09:47 by yenoh             #+#    #+#             */
/*   Updated: 2023/09/19 21:17:43 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

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