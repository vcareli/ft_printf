/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/07 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	ft_buffer(va_list ap, char *buffer)
{
	
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	*str_arg;
	char	buffer[BUFSIZ] = NULL;
	char	tmp[20] = {0};
	int		i = -1;
	int		j = 0;

	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				buffer[j] = (char)va_arg(ap, int);
				j++;
				break ;
			}
			else if (format[i] == 's')
			{
				str_arg = va_arg(ap, char *);
				ft_strlcpy(&buffer[j], str_arg);
				j += ft_strlen(str_arg);
				break ;
			}
			else if (format[i] == 'p')
			{}
			else if (format[i] == 'd')
			{
				//ft_itoa(va_arg(ap, int));
				ft_strlcpy(&buffer[j], tmp);
				j += ft_strlen(str_arg);
				break ;
			}
			else if (format[i] == 'i')
			{}
			else if (format[i] == 'u')
			{}
			else if (format[i] == 'x')
			{}
			else if (format[i] == 'X')
			{}
			else if (format[i] == '%')
			{}
			else
			{}
		}
		else
			buffer[j++] = format[i];
	}
	va_end(ap);
	return (j);
}