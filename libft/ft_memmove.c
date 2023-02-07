/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *origem, size_t n)
{
	unsigned char	*d;
	unsigned char	*o;
	size_t			i;

	d = (unsigned char *)dest;
	o = (unsigned char *)origem;
	i = 0;
	if (dest == origem)
		return (dest);
	if (d > o)
	{
		while (++i <= n)
			d[n - i] = o[n - i];
	}
	else
	{
		while (i < n)
		{
			d[i] = o[i];
			i++;
		}
	}
	return (dest);
}
