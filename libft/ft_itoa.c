/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/11 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_tam(int n);

char	*ft_itoa(int n)
{
	char	*ext;
	long	nb;
	int		i;

	i = 0;
	nb = n;
	ext = (char *)malloc(sizeof(char) * ft_tam(n) + 1);
	if (!ext)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		ext[0] = '-';
	}
	ext[ft_tam(n) - i++] = '\0';
	while (nb > 9)
	{
		ext[ft_tam(n) - i++] = '0' + (nb % 10);
		nb /= 10;
	}
	ext[ft_tam(n) - i++] = '0' + (nb % 10);
	return (ext);
}

static int	ft_tam(int n)
{
	int		taille;
	long	num;

	taille = 0;
	num = n;
	if (num < 0)
	{
		taille++;
		num *= (-1);
	}
	while (num > 9)
	{
		num /= 10;
		taille++;
	}
	taille++;
	return (taille);
}
