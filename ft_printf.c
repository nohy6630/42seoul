/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:25:21 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/24 10:28:02 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char f, va_list args)
{
	if (f == 'c')
		return (ft_printc(va_arg(args, int)));
	if (f == 's')
		return (ft_prints(va_arg(args, char *)));
	if (f == 'p')
		return (ft_printp(va_arg(args, unsigned long)));
	if (f == 'd' || f == 'i')
		return (ft_printd(va_arg(args, int)));
	if (f == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	if (f == 'x' || f == 'X')
		return (ft_printx(va_arg(args, unsigned int), f));
	if (f == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i + 1] != '\0' && str[i] == '%')
		{
			i++;
			len += ft_print_arg(str[++i], args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
