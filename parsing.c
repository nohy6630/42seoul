/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:30:36 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 14:35:32 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_width_height(t_info *info)
{
	int		fd;
	char	*line;
	int		h;
	int		chk;

	fd = open(info->map_path, O_RDONLY);
	if (fd == -1)
		perror_exit("open error");
	chk = get_next_line(fd, &line);
	if(chk == -1)
		perror_exit("gnl error");
	info->w = ft_strlen(line);
	h = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
		if(chk == -1)
			perror_exit("gnl error");
		if (info->w != (int)ft_strlen(line))
		{
			free(line);
			return (0);
		}
		free(line);
		h++;
	}
	free(line);
	chk = close(fd);
	if(chk == -1)
		perror_exit("close error");
	if (h <= 2)
		return (0);
	info->h = h;
	return (1);
}

void	load_map(t_info *info)
{
	int	i;
	int	chk;

	i = -1;
	info->map = (char **)malloc(sizeof(char *) * info->h);
	while (++i < info->h)
	{
		chk = get_next_line(info->fd, &info->map[i]);
		if(chk == -1)
		{
			free_info_num(info, i);
			perror_exit("gnl error");			
		}
	}
}

void	check_wall(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->h)
	{
		if (i == 0 || i == info->h - 1)
		{
			j = -1;
			while (++j < info->w)
			{
				if (info->map[i][j] != '1')
					perror_free_exit("top/bottom wall error", info);
			}
		}
		else
		{
			if (info->map[i][0] != '1' || info->map[i][info->w - 1] != '1')
				perror_free_exit("middle wall error", info);
		}
	}
}

void	check_map_element(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
		{
			if (info->map[i][j] == 'P')
			{
				info->p_cnt++;
				info->y = i;
				info->x = j;
			}
			else if (info->map[i][j] == 'C')
				info->c_cnt++;
			else if (info->map[i][j] == 'E')
				info->e_cnt++;
			else if (info->map[i][j] != '0' && info->map[i][j] != '1')
				perror_free_exit("element error", info);
		}
	}
	if (info->p_cnt != 1 || info->c_cnt < 1 || info->e_cnt != 1)
		perror_free_exit("element error", info);
}

void	parse_map(t_info *info)
{
	if (!check_map_width_height(info))
		perror_exit("rectangular error");
	info->fd = open(info->map_path, O_RDONLY);
	if (info->fd == -1)
		perror_exit("open error");
	load_map(info);
	check_wall(info);
	check_map_element(info);
	if (!check_valid_path(info))
		perror_free_exit("invalid path error", info);
}
