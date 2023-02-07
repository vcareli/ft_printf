/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/10 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		check(char c, char *set);
static size_t	grandeur(const char *s, char *start, char *end);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	tam;
	int				i;
	char			*inicio;
	char			*fim;
	char			*trimee;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && check((char)s1[i], (char *)set))
		i++;
	inicio = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	if (i != -1)
		while (i >= 0 && check((char)s1[i], (char *)set))
			i--;
	fim = (char *)&s1[i];
	tam = grandeur(s1, inicio, fim);
	trimee = malloc(sizeof(char) * tam);
	if (!trimee)
		return (NULL);
	ft_strlcpy(trimee, inicio, tam);
	return (trimee);
}

static int	check(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	grandeur(const char *s, char *start, char *end)
{
	size_t	ret;

	ret = 0;
	if (!*s || end == start)
		ret = 1;
	else
		ret = end - start + 2;
	return (ret);
}
