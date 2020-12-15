/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:41:38 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/27 17:54:20 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *src, const char *key, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*key)
		return ((char *)src);
	while (src[i] && i < len)
	{
		while ((i + j < len) && src[i + j] == key[j] && src[i + j])
			j++;
		if (key[j])
			j = 0;
		else
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
