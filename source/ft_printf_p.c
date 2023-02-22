/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/02/20 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_plen(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
		len += 1;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

void	ft_putp(unsigned long long p)
{
	if (p >= 16)
	{
		ft_putp(p / 16);
		ft_putp(p % 16);
	}
	else if (p < 10)
		ft_putchar_fd(p + '0', 1);
	else if (p > 9)
		ft_putchar_fd(p - 10 + 'a', 1);
}

void    ft_printf_p(unsigned long long p, t_str *s)
{
    s->len += write(1, "0x", 2);
    if (p == 0)
        s->len += write(1, "0", 1);
    else
    {
        ft_putp(p);
        s->len += ft_plen(p);
    }
}