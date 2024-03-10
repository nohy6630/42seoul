/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:15:00 by yenoh             #+#    #+#             */
/*   Updated: 2023/06/27 15:49:37 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H                    

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_arg(char f, va_list args);
int		ft_printc(char c);
int		ft_prints(char *str);
int		ft_printp(unsigned long adr);
int		ft_printd(int n);
int		ft_printu(unsigned int n);
int		ft_printx(unsigned int n, char f);
int		ft_print_percent(void);
size_t	ft_strlen(const char *s);

#endif