/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:11 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 23:16:27 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_info_num(t_info *info, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		free(info->map[i]);
	free(info->map);
}

void	free_dfs_num(t_dfs *dfsi, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		free(dfsi->visited[i]);
	free(dfsi->visited);
}

int	check_map_2(int fd, char **linep, t_info *info, int *hp)
{
	int	chk;

	while (1)
	{
		chk = get_next_line(fd, linep);
		if (chk == -1)
			perror_exit("gnl error");
		if (chk == 0)
			break ;
		if (info->w != (int)ft_strlen(*linep))
		{
			free(*linep);
			return (0);
		}
		free(*linep);
		(*hp)++;
	}
	free(*linep);
	chk = close(fd);
	if (chk == -1)
		perror_exit("close error");
	return (1);
}

void	init_info_2(t_info *info)
{
	int	img_len;

	info->g_img = mlx_xpm_file_to_image(info->mlx, \
	"textures/g.xpm", &img_len, &img_len);
	info->w_img = mlx_xpm_file_to_image(info->mlx, \
	"textures/w.xpm", &img_len, &img_len);
	info->p_img = mlx_xpm_file_to_image(info->mlx, \
	"textures/p.xpm", &img_len, &img_len);
	info->c_img = mlx_xpm_file_to_image(info->mlx, \
	"textures/c.xpm", &img_len, &img_len);
	info->e_img = mlx_xpm_file_to_image(info->mlx, \
	"textures/e.xpm", &img_len, &img_len);
}
