/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:27:34 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 10:49:57 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.dot_in = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}

int		ft_print_format_ext(const char *str, int *i, va_list args, t_flags flg)
{
	while (str[++(*i)])
	{
		if (str[*i] == '0' && flg.precision != -2)
			flg.zero = TRUE;
		else if (str[*i] == '-')
			flg.minus = TRUE;
		else if (str[*i] == '.')
			flg.precision = -2;
		else if (ft_isdigit(str[*i]))
			ft_manage_digits(&flg, str, i);
		else if (str[*i] == '*')
			ft_manage_stars(&flg, args);
		else if (ft_is_coversion(str[*i]))
		{
			flg.type = str[*i];
			return (ft_manage_convs(flg, args));
		}
		else
		{
			(*i)--;
			return (0);
		}
	}
	return (0);
}

int		ft_print_format(const char *str, int *i, va_list args)
{
	t_flags	flags;
	int		count_chars;

	count_chars = 0;
	flags = ft_init_flags();
	count_chars = ft_print_format_ext(str, i, args, flags);
	return (count_chars);
}

int		ft_print_all(const char *str, va_list args)
{
	int		i;
	int		count_chars;

	i = 0;
	count_chars = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count_chars += ft_print_format(str, &i, args);
		else
		{
			ft_putchar_fd(str[i], 1);
			count_chars++;
		}
		i++;
	}
	return (count_chars);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		count_chars;

	count_chars = 0;
	va_start(args, str);
	count_chars += ft_print_all(str, args);
	va_end(args);
	return (count_chars);
}
