/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destino, const char *origin, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len && origin[i] != '\0')
	{
		destino[i] = origin[i];
		i++;
	}
	while (i < len)
	{
		destino[i] = '\0';
		i++;
	}
	return (destino);
}
