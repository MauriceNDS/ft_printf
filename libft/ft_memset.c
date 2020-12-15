/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:03:10 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/23 16:26:37 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int value, size_t len)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char*)array;
	while (i++ < len)
		arr[i - 1] = value;
	return (arr);
}
