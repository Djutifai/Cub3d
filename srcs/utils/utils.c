/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:09:19 by ftassada          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:48 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_error_fd(t_game *game, char *msg, int op, int fd)
{
	if (close(fd) == -1)
		ft_error(game, "е**ть", 0);
	ft_error(game, msg, op);
}

void	ft_error(t_game *game, char *msg, int op)
{
	ft_putstr_fd("Error\n", 2);
	if (op == 0)
		ft_putstr_fd(msg, 2);
	if (op == 1)
		perror(msg);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}

int	ft_open(char *flnm)
{
	int	fd;

	fd = open(flnm, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, flnm, 1);
	return (fd);
}

void	ft_gnl_read(t_game *game, int *gnl, int fd, char **ln)
{
	free(*ln);
	*gnl = ft_get_next_line(fd, ln);
	if (*gnl == -1)
	{
		if (close(fd) == -1)
			ft_error(game, "GNL and close", 0);
		ft_error(game, "GNL", 0);
	}
}
