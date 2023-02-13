/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/09 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_d(va_list arg, const char *f, t_str *s)
{
	int d = va_arg(arg, int);
	ft_putnbr(d);
	s->len += ft_intlen(d, *f);
}

void	ft_printf_s(va_list arg, t_str *s)
{
	char *chr = va_arg(arg, char *);
		if (!chr)
		{
			ft_putstr("(null)");
			s->len += ft_strlen_pf("(null)");
		}
		else
		{
			ft_putstr(chr);
			s->len += ft_strlen_pf(chr);
		}
}

void	ft_printf_x(va_list arg, const char *f, t_str *s)
{
	unsigned int x = va_arg(arg, unsigned int);
	ft_printhexa((unsigned long)x);
	s->len += ft_intlen((int)x, *f);
}
