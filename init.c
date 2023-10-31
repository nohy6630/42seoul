/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:45:35 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/02 21:39:15 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_arr(t_info *info, int ac, char **av)
{
	if (ac < 2)
		exit(EXIT_FAILURE);
	info->str_cnt = get_num_count(ac, av);
	info->parse_cnt = 0;
	make_num_arr(info, ac, av);
}

int	get_idx(int *arr, int n)
{
	int	i;

	i = -1;
	while (arr[++i] != n)
		;
	return (i);
}

void	init_ps(t_info *info, t_ps *ps)
{
	int		*sorted_arr;
	int		i;

	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->cmd_stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack(ps->a);
	init_stack(ps->b);
	init_stack(ps->cmd_stack);
	sorted_arr = (int *)malloc(sizeof(int) * info->str_cnt);
	i = -1;
	while (++i < info->str_cnt)
		sorted_arr[i] = info->num_arr[i];
	quick_sort(sorted_arr, 0, info->str_cnt - 1);
	i = -1;
	while (++i < info->str_cnt)
		push(ps->a, get_idx(sorted_arr, info->num_arr[i]));
	free(sorted_arr);
	ps->cmd_cnt = 0;
}

int	check_sorted(t_ps *ps)
{
	t_node	*tmp;
	int		n;

	if (ps->a->len < 2)
		return (1);
	tmp = ps->a->head;
	n = tmp->num;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (n > tmp->num)
			return (0);
		n = tmp->num;
	}
	return (1);
}

void	free_ps(t_ps *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
	free_stack(ps->cmd_stack);
}
