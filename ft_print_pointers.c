/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:50:08 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 12:59:33 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_hexalen_l(unsigned long long num)
{
	int	counter;

	counter = 1;
	while (num /= 16)
		counter++;
	return (counter);
}

char	*ft_conv_hlen_l(unsigned long long num, int *len)
{
	char	*base;
	char	*res;
	int		i;

	*len = ft_count_hexalen_l(num);
	base = "0123456789abcdef";
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

int		ft_print_p_wflg(t_flags flg, int length, int l, char *num)
{
	int		count_chars;

	if (flg.width > length + 2)
	{
		if (flg.minus == TRUE)
		{
			ft_putstr_fd("0x", 1);
			count_chars = ft_print_with_precision(flg, num, l);
			return (ft_print_width(flg.width, ' ', count_chars + 2));
		}
		if (flg.precision < 0 && flg.zero)
		{
			flg.precision = flg.width - 2;
			ft_print_width(0, ' ', length + 2);
		}
		else
			ft_print_width(flg.width, ' ', length + 2);
		ft_putstr_fd("0x", 1);
		ft_print_with_precision(flg, num, l);
		return (flg.width);
	}
	ft_putstr_fd("0x", 1);
	count_chars = ft_print_with_precision(flg, num, l);
	(length == 0 && l == 0 && num[0] == '0') ? count_chars++ : 1;
	return (count_chars + 2);
}

int		ft_print_p(t_flags flg, va_list args)
{
	char	*num;
	int		l;
	int		length;
	int		ret;

	if (!(num = ft_conv_hlen_l(va_arg(args, unsigned long long), &l)))
		return (ERROR);
	length = l;
	if (flg.precision > l)
		length = flg.precision;
	if (num[0] == '0' && l == 1 && flg.dot_in)
	{
		ret = ft_print_p_wflg(flg, 0, 0, "0");
		free(num);
		return (ret);
	}
	ret = ft_print_p_wflg(flg, length, l, num);
	free(num);
	return (ret);
}
