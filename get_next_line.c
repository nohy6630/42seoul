/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:53:41 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/20 17:10:37 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1024
#endif

int	get_newline_idx(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		size;
	int		idx;
	char	*ret;
	char	*tmp;

	ret = malloc(1);
	ret[0] = 0;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buf[size] = 0;
		idx = get_newline_idx(buf);
		tmp = ret;
		if (idx != -1)
		{
			buf[idx + 1] = 0;
			ret = ft_strjoin(ret, buf);
			free(tmp);
			break ;
		}
		ret = ft_strjoin(ret, buf);
		free(tmp);
	}
	if (ft_strlen(ret) < 1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
