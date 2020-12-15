/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:03:02 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/24 10:07:43 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i++ < len)
	{
		((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
		if (((unsigned char*)dst)[i - 1] == (unsigned char)c)
			return (&dst[i]);
	}
	return (NULL);
}
