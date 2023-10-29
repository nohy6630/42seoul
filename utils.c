/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:30:50 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/29 09:57:14 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info, char *map)
{
	int	img_len;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		perror_exit("infile error");
	close(fd);
	info->map_path = map;
	info->move_cnt = 0;
	info->p_cnt = 0;
	info->c_cnt = 0;
	info->e_cnt = 0;
	info->img_len = 64;
	info->mlx = mlx_init();
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

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->h)
		free(info->map[i]);
	free(info->map);
}

void	perror_exit(char *opt)
{
	write(2, "Error\n", 6);
	write(2, opt, ft_strlen(opt));
	exit(EXIT_FAILURE);
}

void	perror_free_exit(char *opt, t_info *info)
{
	write(2, "Error\n", 6);
	write(2, opt, ft_strlen(opt));
	free_info(info);
	exit(EXIT_FAILURE);
}

int	mlx_destroy_exit(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	free_info(info);
	exit(EXIT_SUCCESS);
}
