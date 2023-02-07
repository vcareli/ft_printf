/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *origem, size_t n)
{
	unsigned char	*d;
	unsigned char	*o;
	size_t			i;

	d = (unsigned char *)dest;
	o = (unsigned char *)origem;
	i = 0;
	if (!n || dest == origem)
		return (dest);
	while (i < n)
	{
		d[i] = o[i];
		i++;
	}
	return (dest);
}
