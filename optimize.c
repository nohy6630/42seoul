/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:52:25 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/03 19:05:43 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_ra_rb(t_ps *ps)
{
	int		check;
	t_node	*tmp;
	t_node	*node;

	check = 0;
	tmp = ps->cmd_stack->head;
	while (tmp)
	{
		if (tmp->next && tmp->num == 5 && tmp->next->num == 6)
		{
			node = tmp;
			tmp = tmp->next;
			node->prev->next = tmp;
			tmp->prev = node;
			free(node);
			tmp->num = 7;
			check = 1;
		}
		tmp = tmp->next;
	}
	return (check);
}

static int	check_rb_ra(t_ps *ps)
{
	int		check;
	t_node	*tmp;
	t_node	*node;

	check = 0;
	tmp = ps->cmd_stack->head;
	while (tmp)
	{
		if (tmp->next && tmp->num == 6 && tmp->next->num == 5)
		{
			node = tmp;
			tmp = tmp->next;
			node->prev->next = tmp;
			tmp->prev = node;
			free(node);
			tmp->num = 7;
			check = 1;
		}
		tmp = tmp->next;
	}
	return (check);
}

void	optimize(t_ps *ps)
{
	while (check_ra_rb(ps) || check_rb_ra(ps))
		;
}
