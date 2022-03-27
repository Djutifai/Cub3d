/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:12:06 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:49 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		first_len;
	int		second_len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	first_len = ft_strlen(s1);
	second_len = ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (first_len + second_len + 1));
	if (strjoin == NULL)
		return (NULL);
	while (i < first_len)
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < (first_len + second_len))
	{
		strjoin[i] = s2[i - first_len];
		i++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
