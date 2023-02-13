/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/09 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

int	ft_intlen(int nb, char c)
{
	int	i = 0;
	int	number;
	int	neg;

	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	if (c == 'd')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	if (c == 'x')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return (0);	
}

void	ft_printhexa(unsigned int x)
{
	char	*hexa = "0123456789abcdef";
	int		res[100];
	int		i = 0;

	while (x >= 16)
	{
		res[1] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putnbr(res[i]);
		i--;
	}
}

const char	*ft_read_text(t_str *s, const char *f)
{
	char	*prox;

	prox = ft_strrchr_pf((char *)f, '%');
	if (prox)
		s->width = prox - f;
	else
		s->width = ft_strlen_pf((char *)f);
	write(1, f, s->width);
	s->len += s->width;
	while (*f && *f != '%')
		++f;
	return (f);
}

const char	*ft_search_arg(va_list arg, const char *f, t_str *s)
{
	if (*f == 'd')
	{
		ft_printf_d(arg, f, s);
	}
	else if (*f == 's')
	{
		ft_printf_s(arg, s);
	}
	else if (*f == 'x')
	{
		ft_printf_x(arg, f, s);
	}
	else
		return (NULL);
	f++;
	return (f);
}
