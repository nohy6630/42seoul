/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:37:38 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 12:37:39 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int	n;

	if (ps->a->len < 2)
		return ;
	n = pop_left(ps->a);
	push(ps->a, n);
}

void	rb(t_ps *ps)
{
	int	n;

	if (ps->b->len < 2)
		return ;
	n = pop_left(ps->b);
	push(ps->b, n);
}

void	rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}

void	rra(t_ps *ps)
{
	int	n;

	if (ps->a->len < 2)
		return ;
	n = pop(ps->a);
	push_left(ps->a, n);
}

void	rrb(t_ps *ps)
{
	int	n;

	if (ps->b->len < 2)
		return ;
	n = pop(ps->b);
	push_left(ps->b, n);
}
