/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chaine;
	size_t	tam;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		tam = ft_strlen(s1) + ft_strlen(s2) + 1;
		chaine = (char *)malloc(tam * sizeof(char));
		if (!chaine)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++j])
			chaine[++i] = s1[j];
		j = -1;
		while (s2[++j])
			chaine[++i] = s2[j];
		chaine[++i] = '\0';
		return (chaine);
		free(chaine);
	}
	return (NULL);
}
