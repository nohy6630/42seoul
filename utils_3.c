/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:56:40 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/24 02:42:22 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx_recur(unsigned int n, char f)
{

}

int	ft_printx(unsigned int n, char f)
{
	int	len;

	len = ft_printx_recur(n, f);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_print_percent(void)
{
	if (write(1, "%%", 1) == -1)
		return (-1);
	return (1);
}
