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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_uitoa(unsigned int n, const char *f)
{
	int		len;
	char	*num;

	len = ft_intlen(n, *f);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int		ft_intlen(int nb, char c)
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
	if (c == 'd' || c == 'i' || c == 'u')
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

void	ft_printhexa(unsigned int x, const char *f, t_str *s)
{
	if (x >= 16)
	{
		ft_printhexa(x/16, f, s);
		ft_printhexa(x%16, f, s);
	}
	else
		if (x <= 9)
		{
			ft_putchar_fd(x + '0', 1);
			s->len += 1;
		}
		else
		{
			if (*f == 'x')
				ft_putchar_fd(x - 10 + 'a', 1);
			if (*f == 'X')
				ft_putchar_fd(x - 10 + 'A', 1);
			s->len += 1;
		}
		
}
