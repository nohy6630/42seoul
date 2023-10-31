/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:31:09 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 14:14:39 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		return (0);
	if (map[i - 4] != '.' || map[i - 3] != 'b' || map[i - 2] != 'e' || \
			map[i - 1] != 'r')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		perror_exit("argument error");
	if (!check_ber(av[1]))
		perror_exit("infile error");
	init_info(&info, av[1]);
	parse_map(&info);
	info.win = mlx_new_window(info.mlx, info.img_len * info.w,
			info.img_len * info.h, "so_long");
	draw_map(&info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &mlx_destroy_exit, &info);
	mlx_loop(info.mlx);
	exit(EXIT_SUCCESS);
	return 0;
}
