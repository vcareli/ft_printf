/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/10 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		combien_mots(char const *s, char c);
static int		grandeur(char const *s, char c, int i);
static char		**alloc(char **tab, char const *s, char c);
static void		*clean(char **tab);

char	**ft_split(char const *s, char c)
{
	char	**ret;

	ret = (char **)malloc((combien_mots(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	if (!alloc(ret, s, c))
		return (clean(ret));
	return (ret);
}

static int	combien_mots(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static int	grandeur(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	*clean(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**alloc(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = (char *)malloc((grandeur(s, c, i) + 1) * sizeof (char));
			if (!tab[j])
				return (NULL);
			while (s[i] && s[i] != c)
				tab [j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
