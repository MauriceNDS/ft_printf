/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:12:07 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/11 09:52:58 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_stars(t_flags *flags, va_list args)
{
	int		num;

	flags->star++;
	num = va_arg(args, int);
	if (num < 0 && flags->precision == -1)
	{
		num = -num;
		flags->minus = TRUE;
	}
	if (flags->precision == -1 && flags->width == 0 && flags->star == 1)
		flags->width = num;
	else if (flags->star == 2 && flags->precision == -1)
		return (ERROR);
	else if (flags->precision == -2 && flags->star <= 2)
	{
		flags->precision = num;
		flags->dot_in = 1;
	}
	if (flags->star > 2)
		return (ERROR);
	return (SUCCESS);
}

void	ft_manage_digits(t_flags *flags, const char *str, int *i)
{
	if (flags->width == 0 && flags->precision == -1)
		while (ft_isdigit(str[*i]))
		{
			flags->width = flags->width * 10 + str[*i] - '0';
			(*i)++;
		}
	else if (flags->precision == -2)
	{
		flags->dot_in = 1;
		flags->precision = 0;
		while (ft_isdigit(str[*i]))
		{
			flags->precision = flags->precision * 10 + str[*i] - '0';
			(*i)++;
		}
	}
	(*i)--;
}
