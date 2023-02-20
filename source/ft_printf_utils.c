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
	num = (char *)calloc((len + 1), sizeof(char));
	if (!num)
		return (0);
	num[len] = '\0';
	len--;
	while (n != 0)
	{
		num[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	//num[0] = (n % 10) + '0';
	return (num);
}

int		ft_intlen(int nb, char c)
{
	int	i = 0;
	int	number;
	int	neg;

	neg = 0;
	number = nb;
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else if (nb == 0)
		i = 1;
	if (c == 'd' || c == 'i' || c == 'u')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
	}
	return (i + neg);
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
