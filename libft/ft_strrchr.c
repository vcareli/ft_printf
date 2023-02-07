/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2022/12/05 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
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
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ch)
			res = &s[i];
		i++;
	}
	return (res);
}
