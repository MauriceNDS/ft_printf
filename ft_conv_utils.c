/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:46:34 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 12:31:15 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*count_char(unsigned long n, unsigned int *count)
{
	char	*res;

	while (n /= 10)
		(*count)++;
	(*count)++;
	if (!(res = malloc(sizeof(char) * (*count + 1))))
		return (NULL);
	return (res);
}

char			*ft_itoa_u(unsigned int n)
{
	char			*res;
	unsigned long	cp;
	unsigned int	count;
	unsigned long	div;
	unsigned int	i;

	count = 0;
	i = 0;
	div = 1;
	cp = (unsigned long)n;
	if (!(res = count_char(cp, &count)))
		return (NULL);
	while (--count)
		div *= 10;
	while (div)
	{
		res[i++] = cp / div + 48;
		cp %= div;
		div /= 10;
	}
	res[i] = '\0';
	return (res);
}

int				ft_print_width(int width, char fill_char, int len)
{
	int		ret;

	ret = width;
	while (width-- > len)
		ft_putchar_fd(fill_char, 1);
	return (ret);
}

int				ft_print_with_precision(t_flags flags, char *str, int len)
{
	int		i;

	i = 0;
	if (*str == '-')
	{
		ft_putchar_fd('-', 1);
		str++;
	}
	while (flags.precision-- > len)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	return (len + i);
}

int				ft_putpres(char *s, int l)
{
	size_t	len;

	len = ft_strlen(s);
	if (l < 0 || l > (int)len)
		;
	else
		len = l;
	write(1, s, len);
	return (len);
}
