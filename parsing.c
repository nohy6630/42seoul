/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:37:03 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 22:34:48 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_num_count(char **nums_str)
{
	int		i;
	int		j;

	i = -1;
	while (nums_str[++i])
	{
		j = -1;
		while (nums_str[i][++j])
		{
			if (j == 0 && (nums_str[i][j] == '-' || nums_str[i][j] == '+'))
				;
			else if (!ft_isdigit(nums_str[i][j]))
			{
				while (nums_str[i])
					free(nums_str[i++]);
				free(nums_str);
				error_exit();
			}
		}
		free(nums_str[i]);
	}
	free(nums_str);
	return (i);
}

int	get_num_count(int ac, char **av)
{
	int		i;
	int		cnt;
	char	**nums_str;

	i = 0;
	cnt = 0;
	while (++i < ac)
	{
		nums_str = ft_split(av[i], ' ');
		cnt += str_num_count(nums_str);
	}
	return (cnt);
}

int	check_num_arr(t_info *info, long long ln)
{
	int	i;

	i = -1;
	while (++i < info->parse_cnt)
	{
		if (info->num_arr[i] == (int)ln)
			return (0);
	}
	return (1);
}

void	fill_num_arr(t_info *info, char **nums_str)
{
	int			i;
	int			check;
	long long	ln;

	i = -1;
	check = 0;
	ln = 0;
	while (nums_str[++i])
	{
		ln = ft_long_atoi(nums_str[i], &check);
		if (check == 1 || !check_num_arr(info, ln))
		{
			while (nums_str[i])
				free(nums_str[i++]);
			free(nums_str);
			error_free_exit(info);
		}
		info->num_arr[info->parse_cnt] = (int)ln;
		info->parse_cnt++;
		free(nums_str[i]);
	}
	free(nums_str);
}

void	make_num_arr(t_info *info, int ac, char **av)
{
	int		i;
	char	**nums_str;

	i = 0;
	info->num_arr = (int *)malloc(sizeof(int) * info->str_cnt);
	while (++i < ac)
	{
		if (!check_space(av[i]))
			error_free_exit(info);
		nums_str = ft_split(av[i], ' ');
		fill_num_arr(info, nums_str);
	}
}
