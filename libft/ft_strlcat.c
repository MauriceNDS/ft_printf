/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:07:26 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/24 13:40:32 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	i = a;
	if (dstsize == 0)
		return (b);
	while (src[i - a] && i < dstsize - 1)
	{
		dst[i] = src[i - a];
		i++;
	}
	if (a > dstsize)
		return (b + dstsize);
	dst[i] = '\0';
	return (a + b);
}
