/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:52:43 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/25 15:30:05 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		last_idx;
	int		first_idx;
	size_t	len;

	first_idx = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[first_idx] && ft_inset(s1[first_idx], set))
		first_idx++;
	last_idx = ft_strlen(s1) - 1;
	while (last_idx >= first_idx && ft_inset(s1[last_idx], set))
		last_idx--;
	len = last_idx - first_idx + 1;
	return (ft_substr(s1, first_idx, len));
}
