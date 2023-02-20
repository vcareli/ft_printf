/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/07 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include "libft.h"

typedef struct s_str
{
	int		len;
	int		width;
}	t_str;

int				ft_printf(const char *format, ...);
const char		*ft_search_arg(va_list arg, const char *f, t_str *s);

void			ft_printf_d(va_list arg, const char *f, t_str *s);
void			ft_printf_s(va_list arg, t_str *s);
void			ft_printf_x(va_list arg, const char *f, t_str *s);
void			ft_print_c(va_list arg, t_str *s);
void			ft_printf_u(va_list arg, const char *f, t_str *s);

void			ft_putnbr(int nb);
int				ft_strlen_pf(char *str);
char			*ft_strrchr_pf(const char *str, int c);

void			ft_putstr(char *str);
char			*ft_uitoa(unsigned int n, const char *f);
int				ft_intlen(int nb, char c);
void			ft_printhexa(unsigned int x, const char *f, t_str *s);
int				ft_len_u(unsigned int nb);

void			ft_printf_p(unsigned long long p, t_str *s);
void			ft_putp(unsigned long long p);
int				ft_plen(unsigned long long p);

#endif
