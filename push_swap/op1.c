/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:37:46 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 12:37:46 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	int	n;

	if (ps->a->len < 2)
		return ;
	n = ps->a->head->num;
	ps->a->head->num = ps->a->head->next->num;
	ps->a->head->next->num = n;
}

void	sb(t_ps *ps)
{
	int	n;

	if (ps->b->len < 2)
		return ;
	n = ps->b->head->num;
	ps->b->head->num = ps->b->head->next->num;
	ps->b->head->next->num = n;
}

void	ss(t_ps *ps)
{
	sa(ps);
	sb(ps);
}

void	pa(t_ps *ps)
{
	int	n;

	if (ps->b->len < 1)
		return ;
	n = pop_left(ps->b);
	push_left(ps->a, n);
}

void	pb(t_ps *ps)
{
	int	n;

	if (ps->a->len < 1)
		return ;
	n = pop_left(ps->a);
	push_left(ps->b, n);
}
