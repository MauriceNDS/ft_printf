/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:16:36 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/26 15:30:45 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skipspace(char *str)
{
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	return (str);
}

int			ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	result = 0;
	str = ft_skipspace((char*)str);
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - 48;
		str++;
		if (result >= LONG_MAX && sign == -1)
			return (0);
		else if (result > LONG_MAX && sign == 1)
			return (-1);
	}
	return ((int)(result * sign));
}
