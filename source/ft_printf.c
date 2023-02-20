/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/09 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

const char	*ft_search_arg(va_list arg, const char *f, t_str *s)
{
	if (*f == 'c')	//ok
		ft_print_c(arg, s);
	else if (*f == 's')	//ok
		ft_printf_s(arg, s);
	else if (*f == 'p')
		ft_printf_p(va_arg(arg, unsigned long long), s);
	else if (*f == 'd' || *f == 'i')	//ok
		ft_printf_d(arg, f, s);
	else if (*f == 'u')
		ft_printf_u(arg, f, s);
	else if (*f == 'x' || *f == 'X')	//ok
		ft_printf_x(arg, f, s);
	else if (*f == '%')		//ok
	{
		ft_putchar_fd(*f, 1);
		s->len += 1;
	}
	f++;
	return (f);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_str		str;

	str.len = 0;
	str.width = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format + 1, &str);
		else
		{
			write(1, format, 1);
			str.len += 1;
			format++;
		}
		if (!format)
		{
			ft_putstr("(null)");
			va_end(arg);
			return (str.len);
		}
	}
	va_end(arg);
	return (str.len);
}
