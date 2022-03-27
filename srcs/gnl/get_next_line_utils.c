/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:14:06 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:49 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_all(int fd, char ***rest, int key)
{
	int	i;

	if (*rest != NULL && fd >= 0)
	{
		free((*rest)[fd]);
		(*rest)[fd] = NULL;
		i = 0;
		while (i < 1024 && ((*rest)[i] == NULL || (*rest)[i][0] == '\0'))
			i++;
		if (i == 1024)
		{
			while (i > 0)
			{
				i--;
				if ((*rest)[i] != NULL)
				{
					free((*rest)[i]);
					(*rest)[i] = NULL;
				}
			}
			free(*rest);
			*rest = NULL;
		}
	}
	return (key);
}
