/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:51:18 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:49 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	int		i;

	if (!lst)
		return (NULL);
	ptr = lst;
	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		ptr = ptr->next;
		i--;
	}
	return (ptr);
}
