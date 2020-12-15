/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:19:41 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 10:30:50 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_flags flags, va_list args)
{
	size_t	count_chars;
	char	fill_char;
	char	character;

	fill_char = ' ';
	character = va_arg(args, int);
	count_chars = 1;
	if (flags.width > 1)
	{
		count_chars = flags.width;
		if (flags.minus == TRUE)
		{
			ft_putchar_fd(character, 1);
			while (--flags.width)
				ft_putchar_fd(fill_char, 1);
			return (count_chars);
		}
		else if (flags.zero == TRUE)
			fill_char = '0';
		while (--flags.width)
			ft_putchar_fd(fill_char, 1);
	}
	ft_putchar_fd(character, 1);
	return (count_chars);
}

int		ft_print_symb(t_flags flags)
{
	size_t	count_chars;
	char	fill_char;

	fill_char = ' ';
	count_chars = 1;
	if (flags.width > 1)
	{
		count_chars = flags.width;
		if (flags.minus == TRUE)
		{
			ft_putchar_fd('%', 1);
			while (--flags.width)
				ft_putchar_fd(fill_char, 1);
			return (count_chars);
		}
		else if (flags.zero == TRUE)
			fill_char = '0';
		while (--flags.width)
			ft_putchar_fd(fill_char, 1);
		ft_putchar_fd('%', 1);
		return (count_chars);
	}
	ft_putchar_fd('%', 1);
	return (count_chars);
}

int		ft_print_s_wflg(t_flags flags, int length, int len, char *str)
{
	char	fill_char;
	int		count_chars;

	fill_char = ' ';
	if (flags.width > length)
	{
		count_chars = flags.width;
		if (len > flags.precision && flags.precision >= 0)
			flags.width += len - flags.precision;
		if (flags.minus == TRUE)
		{
			ft_putpres(str, flags.precision);
			while (flags.width-- - len)
				ft_putchar_fd(fill_char, 1);
			return (count_chars);
		}
		else if (flags.zero == TRUE)
			fill_char = '0';
		while (flags.width-- - len)
			ft_putchar_fd(fill_char, 1);
		ft_putpres(str, flags.precision);
		return (count_chars);
	}
	return (ft_putpres(str, flags.precision));
}

int		ft_print_s(t_flags flags, va_list args)
{
	int		len;
	int		length;
	char	*string;

	if ((string = va_arg(args, char*)) == NULL)
		string = "(null)";
	len = ft_strlen(string);
	length = len;
	if (flags.precision < len && flags.precision >= 0 && flags.dot_in == 1)
		length = flags.precision;
	return (ft_print_s_wflg(flags, length, len, string));
}
