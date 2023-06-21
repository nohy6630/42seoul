/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:53:41 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/21 12:36:47 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_data(char *data)
{
	char	*ret;

	if (!data)
	{
		ret = malloc(1);
		ret[0] = 0;
		return (ret);
	}
	return (data);
}

char	*read_data(char *data, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		size;
	char	*tmp;

	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		buf[size] = 0;
		data = init_data(data);
		tmp = ft_strjoin(data, buf);
		free(data);
		data = tmp;
		if (size == 0 || ft_strchr(data, '\n'))
			break ;
	}
	return (data);
}

char	*get_next_data(char *ret)
{
	int		i;
	char	*data;

	i = 0;
	while (ret[i] && ret[i] != '\n')
		i++;
	if (ret[i] == '\n')
		i++;
	if (!ret[i])
		data = NULL;
	else
		data = ft_strdup(ret + i);
	ret[i] = 0;
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*ret;

	ret = read_data(data, fd);
	if (!ret)
	{
		if (data)
		{
			free(data);
			data = NULL;
		}
		return (NULL);
	}
	data = get_next_data(ret);
	if (ft_strlen(ret) < 1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
