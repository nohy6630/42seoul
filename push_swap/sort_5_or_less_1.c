/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:49 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 22:34:29 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_2(int *arr, t_ps *ps)
{
	if (arr[0] < arr[1])
		cmd_update(ps, 8, rra);
	else
	{
		cmd_update(ps, 0, sa);
		cmd_update(ps, 8, rra);
	}
}

void	sort3(t_ps *ps)
{
	int	*arr;

	if (check_sorted(ps))
		return ;
	arr = to_array(ps->a);
	if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		cmd_update(ps, 0, sa);
		cmd_update(ps, 5, ra);
	}
	else if (arr[1] < arr[0] && arr[1] < arr[2])
	{
		if (arr[0] < arr[2])
			cmd_update(ps, 0, sa);
		else
			cmd_update(ps, 5, ra);
	}
	else
		sort_3_2(arr, ps);
	free(arr);
}

void	sort4(t_ps *ps)
{
	int	i;
	int	min;

	i = -1;
	min = get_min(ps->a);
	while (++i < 4)
	{
		if (ps->a->head->num == min)
		{
			cmd_update(ps, 4, pb);
			break ;
		}
		else
			ra(ps);
	}
	sort3(ps);
	cmd_update(ps, 3, pa);
}

void	sort5(t_ps *ps)
{
	int		i;
	int		pb_i;
	int		m;

	i = -1;
	pb_i = 0;
	m = get_median(ps->a);
	while (++i < 5 && pb_i < ps->a->len / 2)
	{
		if (ps->a->head->num < m)
		{
			cmd_update(ps, 4, pb);
			pb_i++;
		}
		else
			cmd_update(ps, 5, ra);
	}
	sort3(ps);
	cmd_update(ps, 3, pa);
	cmd_update(ps, 3, pa);
	if (ps->a->head->num > ps->a->head->next->num)
		cmd_update(ps, 0, sa);
}

void	sort_5_or_less(t_ps *ps)
{
	if (ps->a->len == 2)
		sort2(ps);
	else if (ps->a->len == 3)
		sort3(ps);
	else if (ps->a->len == 4)
		sort4(ps);
	else if (ps->a->len == 5)
		sort5(ps);
}
