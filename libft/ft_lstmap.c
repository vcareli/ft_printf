/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:32:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nouvelle_list;
	t_list	*nouveau_elem;
	void	*aux;

	if (!f || !del)
		return (NULL);
	nouvelle_list = NULL;
	while (lst)
	{
		aux = (f)(lst->content);
		nouveau_elem = ft_lstnew(aux);
		if (!nouveau_elem)
		{
			free(aux);
			ft_lstclear(&nouvelle_list, del);
			break ;
		}
		ft_lstadd_back(&nouvelle_list, nouveau_elem);
		lst = lst->next;
	}
	return (nouvelle_list);
}
