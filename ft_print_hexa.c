/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:03:58 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/11 13:33:35 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_hexalen(unsigned int num)
{
	int	counter;

	counter = 1;
	while (num /= 16)
		counter++;
	return (counter);
}

char	*ft_convert_hexa(int type, unsigned int num, int *len)
{
	char	*base;
	char	*res;
	int		i;

	*len = ft_count_hexalen(num);
	base = "0123456789abcdef";
	if (type != 'x')
		base = "0123456789ABCDEF";
	if (!(res = malloc(*len + 1)))
		return (NULL);
	i = 1;
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[*len - i++] = base[num % 16];
		num /= 16;
	}
	res[*len] = 0;
	return (res);
}

int		ft_print_x_wflg(t_flags flags, int length, int len, char *num)
{
	int		count_chars;

	if (flags.width > length)
	{
		if (flags.minus == TRUE)
		{
			count_chars = ft_print_with_precision(flags, num, len);
			return (ft_print_width(flags.width, ' ', count_chars));
		}
		if (flags.precision > len)
			ft_print_width(flags.width, ' ', flags.precision);
		else if (flags.zero == TRUE && flags.dot_in == FALSE)
			flags.precision = flags.width;
		else
			ft_print_width(flags.width, ' ', len);
		ft_print_with_precision(flags, num, len);
		return (flags.width);
	}
	count_chars = ft_print_with_precision(flags, num, len);
	return (count_chars);
}

int		ft_print_x(t_flags flags, va_list args)
{
	char	*num;
	int		len;
	int		ret;
	int		length;

	num = ft_convert_hexa(flags.type, va_arg(args, unsigned int), &len);
	length = len;
	if (flags.precision > len)
		length = flags.precision;
	if (flags.precision == 0 && num[0] == '0')
	{
		free(num);
		return (ft_print_x_wflg(flags, 0, 0, ""));
	}
	ret = ft_print_x_wflg(flags, length, len, num);
	free(num);
	return (ret);
}
