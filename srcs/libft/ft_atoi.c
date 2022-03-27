/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:50:56 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:47 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atoi_error(void)
{
	write(2, "Error\nft_atoi\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int		neg;
	ssize_t	num;
	size_t	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
		if (!ft_isdigit(str[i]))
			atoi_error();
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + neg * (str[i++] - '0');
		if (num < -2147483648 || num > 2147483647)
			atoi_error();
	}
	neg = num;
	return (neg);
}
