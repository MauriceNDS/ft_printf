/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:54:56 by adel-sol          #+#    #+#             */
/*   Updated: 2020/12/15 10:35:11 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define TRUE		1
# define FALSE		0
# define ERROR		0
# define SUCCESS	1

typedef struct	s_flags
{
	int			type;
	int			zero;
	int			star;
	int			dot_in;
	int			minus;
	int			width;
	int			precision;
}				t_flags;

int				ft_manage_stars(t_flags *flags, va_list args);
void			ft_manage_digits(t_flags *flags, const char *str, int *i);
int				ft_is_coversion(const char c);
int				ft_putpres(char *s, int l);
int				ft_manage_convs(t_flags flags, va_list args);
int				ft_print_c(t_flags flags, va_list args);
int				ft_print_s(t_flags flags, va_list args);
int				ft_print_p(t_flags flags, va_list args);
int				ft_print_d(t_flags flags, va_list args);
int				ft_print_u(t_flags flags, va_list args);
int				ft_print_x(t_flags flags, va_list args);
int				ft_print_symb(t_flags flags);
char			*ft_itoa_u(unsigned int n);
int				ft_print_with_precision(t_flags flags, char *str, int len);
int				ft_print_width(int width, char fill_char, int len);
int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));

#endif
