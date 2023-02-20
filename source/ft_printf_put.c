/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/09 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"


void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar_fd(nb + '0', 1);
}

int		ft_strlen_pf(char *str)
{
	int	total;

	total = 0;
	while (str[total] != '\0')
	{
		total++;
	}
	return (total);
}

char	*ft_strrchr_pf(const char *str, int c)
{
	int		i;
	char	ch;
	char	*s;
	char	*res;

	i = 0;
	ch = (char)c;
	s = (char *)str;
	res = NULL;
	if (ch == '\0')
		return (s + ft_strlen_pf(s));
	while (s[i])
	{
		if (s[i] == ch)
			res = &s[i];
		i++;
	}
	return (res);
}
