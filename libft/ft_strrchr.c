/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:45:52 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/26 15:04:17 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = -1;
	last = NULL;
	while (s[++i])
		if (s[i] == (char)c)
			last = (char*)&s[i];
	if (s[i] == (char)c)
		last = (char*)&s[i];
	return (last);
}
