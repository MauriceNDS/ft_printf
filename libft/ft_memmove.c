/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:12:17 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/25 15:43:13 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char*)dst;
	usrc = (unsigned char*)src;
	if (!dst && !src)
		return (NULL);
	if (src > dst)
		ft_memcpy(udst, usrc, len);
	else
	{
		while (len)
		{
			udst[len - 1] = usrc[len - 1];
			len--;
		}
	}
	return (udst);
}
