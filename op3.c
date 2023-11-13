/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:37:27 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 22:34:59 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
}

void	print_cmd(int n)
{
	if (n == 0)
		ft_printf("sa\n");
	else if (n == 1)
		ft_printf("sb\n");
	else if (n == 2)
		ft_printf("ss\n");
	else if (n == 3)
		ft_printf("pa\n");
	else if (n == 4)
		ft_printf("pb\n");
	else if (n == 5)
		ft_printf("ra\n");
	else if (n == 6)
		ft_printf("rb\n");
	else if (n == 7)
		ft_printf("rr\n");
	else if (n == 8)
		ft_printf("rra\n");
	else if (n == 9)
		ft_printf("rrb\n");
	else if (n == 10)
		ft_printf("rrr\n");
}

void	print_all_cmd(t_stack *cmd_stack)
{
	t_node	*tmp;

	tmp = cmd_stack->head;
	while (tmp)
	{
		print_cmd(tmp->num);
		tmp = tmp->next;
	}
}

void	cmd_update(t_ps *ps, int n, void (*f)(t_ps *))
{
	f(ps);
	push(ps->cmd_stack, n);
	ps->cmd_cnt++;
}
