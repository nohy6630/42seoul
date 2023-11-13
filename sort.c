/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:35 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 12:36:36 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stack_idx(t_stack *stack, int n)
{
	t_node	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp && tmp->num != n)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	set_rotate(t_ps *ps, int i, int chunk)
{
	int	min;
	int	max;
	int	j;
	int	t;

	min = 0;
	max = ps->a->len;
	j = i - 1;
	while (++j <= i + chunk)
	{
		t = get_stack_idx(ps->a, j);
		if (t < min)
			min = t;
		if (t > max)
			max = t;
	}
	if (min < ps->a->len - max)
		return (1);
	return (0);
}

void	a_to_b(t_ps *ps, int i, int chunk)
{
	while (ps->a->len > 0)
	{
		if (ps->a->head->num <= i)
		{
			cmd_update(ps, 4, pb);
			i++;
		}
		else if (ps->a->head->num > i && ps->a->head->num <= i + chunk)
		{
			cmd_update(ps, 4, pb);
			cmd_update(ps, 6, rb);
			i++;
		}
		else
		{
			if (set_rotate(ps, i, chunk))
				cmd_update(ps, 5, ra);
			else
				cmd_update(ps, 8, rra);
		}
	}
}

static void	max_to_top(t_ps *ps)
{
	int	max;
	int	max_idx;

	max = get_max(ps->b);
	max_idx = get_stack_idx(ps->b, max);
	if (max_idx < ps->b->len / 2)
	{
		while (ps->b->head->num != max)
			cmd_update(ps, 6, rb);
	}
	else
	{
		while (ps->b->head->num != max)
			cmd_update(ps, 9, rrb);
	}
}

void	b_to_a(t_ps *ps)
{
	while (ps->b->len > 0)
	{
		max_to_top(ps);
		cmd_update(ps, 3, pa);
	}
}
