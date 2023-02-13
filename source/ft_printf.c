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
			format = ft_read_text(&str, format);
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
