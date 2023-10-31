/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:11 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/31 14:06:12 by yenoh            ###   ########.fr       */
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