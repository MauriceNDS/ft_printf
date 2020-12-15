/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:02:07 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/11 13:34:33 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_d_wflg(t_flags flg, int length, int l, char *num)
{
	int		count_chars;

	if (flg.width > length)
	{
		if (flg.minus == TRUE)
		{
			count_chars = ft_print_with_precision(flg, num, l);
			return (ft_print_width(flg.width, ' ', count_chars));
		}
		if (flg.precision < 0 && flg.zero)
		{
			flg.precision = flg.width;
			ft_print_width(0, ' ', length);
		}
		else if (flg.zero == TRUE && flg.dot_in == FALSE)
			flg.precision = flg.width;
		else
			ft_print_width(flg.width, ' ', length);
		ft_print_with_precision(flg, num, l);
		return (flg.width);
	}
	count_chars = ft_print_with_precision(flg, num, l);
	return (count_chars);
}

int		ft_print_d(t_flags flags, va_list args)
{
	char	*num;
	int		len;
	int		length;
	int		ret;

	if (!(num = ft_itoa(va_arg(args, int))))
		return (ERROR);
	len = ft_strlen(num);
	length = len;
	if (num[0] == '-')
		flags.precision++;
	if (flags.precision > len)
		length = flags.precision;
	if (flags.precision == 0 && num[0] == '0')
	{
		free(num);
		return (ft_print_d_wflg(flags, 0, 0, ""));
	}
	ret = ft_print_d_wflg(flags, length, len, num);
	free(num);
	return (ret);
}

int		ft_print_u_wflg(t_flags flags, int length, int len, char *num)
{
	int		count_chars;

	if (flags.width > length)
	{
		if (flags.minus == TRUE)
		{
			count_chars = ft_print_with_precision(flags, num, len);
			return (ft_print_width(flags.width, ' ', count_chars));
		}
		if (flags.precision < 0 && flags.zero)
		{
			flags.precision = flags.width;
			ft_print_width(0, ' ', length);
		}
		else
			ft_print_width(flags.width, ' ', length);
		ft_print_with_precision(flags, num, len);
		return (flags.width);
	}
	count_chars = ft_print_with_precision(flags, num, len);
	return (count_chars);
}

int		ft_print_u(t_flags flags, va_list args)
{
	char	*num;
	int		len;
	int		ret;
	int		length;

	if (!(num = ft_itoa_u(va_arg(args, unsigned int))))
		return (ERROR);
	len = ft_strlen(num);
	length = len;
	if (flags.precision > len)
		length = flags.precision;
	if (flags.precision == 0 && num[0] == '0')
	{
		free(num);
		return (ft_print_u_wflg(flags, 0, 0, ""));
	}
	ret = ft_print_u_wflg(flags, length, len, num);
	free(num);
	return (ret);
}
