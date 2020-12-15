/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:13:28 by adel-sol          #+#    #+#             */
/*   Updated: 2020/11/26 15:05:30 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_split(char **res, int j)
{
	while (j >= 0)
		free(res[j--]);
	free(res);
	return (NULL);
}

static int		count_words(const char *s, char c)
{
	int	counter;
	int	word;

	counter = 0;
	word = 0;
	while (*s)
	{
		if (*s == c)
			word = 0;
		else if (word == 0)
		{
			word = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static int		words_len(const char *s, char c, int pos)
{
	int		i;

	i = 0;
	while (s[pos] && s[pos] != c)
	{
		i++;
		pos++;
	}
	return (i);
}

static char		**split(char **res, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (k == 0)
				if (!(res[j] = malloc(sizeof(char) *
					(words_len(s, c, i) + 1))))
					return (free_split(res, j - 1));
			res[j][k] = s[i];
			res[j][++k] = '\0';
		}
		if ((s[i] == c && s[i + 1] != c && k > 0))
		{
			j++;
			k = 0;
		}
	}
	return (res);
}

char			**ft_split(const char *s, char c)
{
	char	**res;
	int		cw;

	if (!s)
		return (NULL);
	cw = count_words(s, c);
	if (!(res = malloc(sizeof(*res) * (cw + 1))))
		return (NULL);
	if (!(res = split(res, s, c)))
		return (NULL);
	res[cw] = 0;
	return (res);
}
