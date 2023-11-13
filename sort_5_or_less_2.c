/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:42 by yenoh             #+#    #+#             */
/*   Updated: 2023/11/13 12:36:43 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j)
			swap(&arr[j], &arr[pivot]);
		else
			swap(&arr[i], &arr[j]);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	get_min(t_stack *stack)
{
	int	*arr;
	int	n;

	arr = to_array(stack);
	quick_sort(arr, 0, stack->len - 1);
	n = arr[0];
	free(arr);
	return (n);
}

int	get_median(t_stack *stack)
{
	int	*arr;
	int	n;

	arr = to_array(stack);
	quick_sort(arr, 0, stack->len - 1);
	n = arr[stack->len / 2];
	free(arr);
	return (n);
}

int	get_max(t_stack *stack)
{
	int	*arr;
	int	n;

	arr = to_array(stack);
	quick_sort(arr, 0, stack->len - 1);
	n = arr[stack->len - 1];
	free(arr);
	return (n);
}

void	sort2(t_ps *ps)
{
	if (ps->a->head->num > ps->a->head->next->num)
		cmd_update(ps, 0, sa);
}
