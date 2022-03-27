/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:53:53 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:49 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newls;
	t_list	*page;

	if (!lst)
		return (NULL);
	newls = ft_lstnew(f(lst->content));
	if (!newls)
	{
		ft_lstdelone(newls, del);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		page = ft_lstnew(f(lst->content));
		if (!page)
		{
			ft_lstclear(&newls, del);
			return (NULL);
		}
		ft_lstadd_back(&newls, page);
	}
	return (newls);
}
