/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:24:45 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/01 22:43:18 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_exit(t_info *info)
{
	free(info->num_arr);
	exit(EXIT_FAILURE);
}

void	error_free_exit(t_info *info)
{
	write(2, "Error\n", 6);
	free(info->num_arr);
	exit(EXIT_FAILURE);
}

void	print_ps(t_ps *ps)
{
	t_node	*t1;
	t_node	*t2;

	t1 = ps->a->head;
	t2 = ps->b->head;
	while (t1 || t2)
	{
		if (t1)
		{
			ft_printf("%-10d", t1->num);
			t1 = t1->next;
		}
		else
			ft_printf("          ");
		if (t2)
		{
			ft_printf("%d", t2->num);
			t2 = t2->next;
		}
		ft_printf("\n");
	}
	ft_printf("-         -\n");
	ft_printf("a         b\n");
	ft_printf("---------------------------\n\n");
}

void	swap(int *n1, int *n2)
{
	int	t;

	t = *n1;
	*n1 = *n2;
	*n2 = t;
}
