/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:24:12 by yenoh             #+#    #+#             */
/*   Updated: 2023/10/29 09:06:10 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_start(t_info *info, t_dfs *dfsi)
{
    int		i;
    int		j;

    i=-1;
    while(++i<info->h)
    {
        j=-1;
        while(++j<info->w)
        {
            if(info->map[i][j]=='P'){
				dfsi->sx=j;
				dfsi->sy=i;
            }
        }
    }
}

void dfs(t_info *info, t_dfs *dfsi, int x, int y)
{
	if(dfsi->valid)
		return;
	if(x<0 || x >= info->w || y<0 || y>=info->h)
		return;
	if(dfsi->visited[y][x]||info->map[y][x]=='1')
		return;
	dfsi->visited[y][x]=1;
	if(info->map[y][x]=='E')
	{
		dfsi->valid=1;
		return;
	}
	dfs(info,dfsi,x-1,y);
	dfs(info,dfsi,x+1,y);
	dfs(info,dfsi,x,y-1);
	dfs(info,dfsi,x,y+1);
}

void init_visited(t_info *info, t_dfs *dfsi)
{
	int i;
	int j;
	
	dfsi->visited=(char **)malloc(sizeof(char*)*info->h);
	i=-1;
	while(++i<info->h)
		dfsi->visited[i]=(char*)malloc(sizeof(char)*info->w);
	i=-1;
	while(++i<info->h)
	{
		j=-1;
		while(++j<info->w)
			dfsi->visited[i][j]=0;
	}
}

int check_valid_path(t_info *info)
{
	t_dfs dfsi;
	int i;
	
	dfsi.valid=0;
	init_visited(info, &dfsi);
	find_start(info, &dfsi);
	dfs(info, &dfsi, dfsi.sx, dfsi.sy);
	i=-1;
	while(++i<info->h)
		free(dfsi.visited[i]);
	free(dfsi.visited);
	return dfsi.valid;
}