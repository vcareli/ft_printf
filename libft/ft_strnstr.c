/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *search, size_t len)
{
	size_t		i;
	char		*s1_aux;
	char		*search_aux;

	if (!ft_strlen(search))
		return ((char *)s1);
	if (!ft_strlen(s1) || len < ft_strlen(search))
		return (0);
	i = len - ft_strlen(search) + 1;
	while (i-- && *s1)
	{
		s1_aux = (char *)s1;
		search_aux = (char *)search;
		while (*search_aux && *search_aux == *s1_aux)
		{
			++s1_aux;
			++search_aux;
		}
		if (!*search_aux)
			return ((char *)s1);
		++s1;
	}
	return (0);
}
