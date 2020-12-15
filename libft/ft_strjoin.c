/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:13:12 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/25 12:52:23 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	i = -1;
	while (++i < size1)
		res[i] = s1[i];
	while (i < size1 + size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
