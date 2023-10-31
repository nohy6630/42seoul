/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:39:01 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/05 23:25:07 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk(int len)
{
	if (len < 100)
		return (15);
	return (30);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_ps	ps;
	int		chunk;

	init_arr(&info, ac, av);
	init_ps(&info, &ps);
	if (check_sorted(&ps))
	{
		free_ps(&ps);
		free_exit(&info);
	}
	chunk = get_chunk(ps.a->len);
	if (info.str_cnt < 6)
		sort_5_or_less(&ps);
	else
	{
		a_to_b(&ps, 0, chunk);
		b_to_a(&ps);
	}
	optimize(&ps);
	print_all_cmd(ps.cmd_stack);
	free(info.num_arr);
	free_ps(&ps);
}
