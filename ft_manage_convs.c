/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:07:37 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 10:33:05 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_coversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	return (FALSE);
}

int		ft_manage_convs(t_flags flags, va_list args)
{
	int		count_chars;

	count_chars = 0;
	if (flags.precision == -2 && flags.dot_in == FALSE)
	{
		flags.dot_in = 1;
		flags.precision = 0;
	}
	if (flags.type == 'c')
		count_chars = ft_print_c(flags, args);
	else if (flags.type == 's')
		count_chars = ft_print_s(flags, args);
	else if (flags.type == 'p')
		count_chars = ft_print_p(flags, args);
	else if (flags.type == 'd' || flags.type == 'i')
		count_chars = ft_print_d(flags, args);
	else if (flags.type == 'u')
		count_chars = ft_print_u(flags, args);
	else if (flags.type == 'x' || flags.type == 'X')
		count_chars = ft_print_x(flags, args);
	else if (flags.type == '%')
		count_chars = ft_print_symb(flags);
	return (count_chars);
}
