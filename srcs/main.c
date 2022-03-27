/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:56:05 by scoach            #+#    #+#             */
/*   Updated: 2022/03/27 17:21:19 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_parse_map(t_game *data, int fd)
{
	int		gnl;
	int		l;

	ft_parse_params(data, &gnl, fd);
	ft_gnl_read(data, &gnl, fd, data->gnln);
	while (gnl != 0 && (*data->gnln)[0] == '\0')
		ft_gnl_read(data, &gnl, fd, data->gnln);
	while (gnl != 0)
	{
		l = ft_strlen(*data->gnln);
		if (l > data->width)
			data->width = l;
		if ((*data->gnln)[0] == '\0'
			|| ft_arr_plus_one(&(data->map), *data->gnln, 0, l) == NULL)
			ft_error(data, "map divided", 0);
		ft_gnl_read(data, &gnl, fd, data->gnln);
	}
	l = ft_strlen(*data->gnln);
	if (ft_arr_plus_one(&(data->map), *data->gnln, 0, l) == NULL)
		ft_error(data, "last string of map did't parsed", 0);
}

static void	ft_check_format(char *name)
{
	int	i;
	int	lenBen;

	lenBen = ft_strlen(name);
	if (lenBen > 254)
		ft_error(NULL, "Invalid filename: too many characters", 0);
	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '?' || name[i] == '<' || name[i] == '>'
			|| name[i] == '*' || name[i] == '"' || name[i] == '|')
			ft_error(NULL, "Invalid filename: illegal characters", 0);
		i++;
	}
	if (name[lenBen - 4] != '.' || name[lenBen - 3] != 'c' || name[lenBen - 2] != 'u'
		|| name[lenBen - 1] != 'b')
		ft_error(NULL, "Invalid format: file must have format \".cub\" ", 0);
}

void	ft_cub(t_game *data)
{
	t_pixel		*pixel;
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		exit(EXIT_FAILURE);
	data->raycast = raycast;
	raycast->mlx = mlx_init();
	init_st_rc(data, raycast);
	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		exit(EXIT_FAILURE);
	raycast->pixel = pixel;
	raycast->win = mlx_new_window(raycast->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "privetyli");
	pixel->img = mlx_new_image(raycast->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	pixel->addr = mlx_get_game_addr(pixel->img, &pixel->bpp,
			&pixel->line_len, &pixel->endian);
	mlx_hook(raycast->win, 2, 0, keypress, raycast->keys);
	mlx_hook(raycast->win, 3, 0, keyrelease, raycast->keys);
	mlx_hook(raycast->win, 17, 0, free_all, raycast);
	mlx_loop_hook(raycast->mlx, render, data);
	mlx_loop(raycast->mlx);
}

int	main(int argc, char *argv[])
{
	t_game		*data;
	int			fd;

	if (argc < 2)
		ft_error(NULL, "Too few arguments", 0);
	if (argc > 2)
		ft_error(NULL, "Too many arguments", 0);
	ft_check_format(argv[1]);
	fd = ft_open(argv[1]);
	data = (t_game *)malloc(sizeof(t_game));
	if (data == NULL)
		ft_error(data, "Data initialization", 0);
	ft_bzero(data, sizeof(t_game));
	data->map = ft_calloc(1, sizeof(char *));
	if (data->map == NULL)
		ft_error(data, "ft_calloc for map", 0);
	ft_parse_map(data, fd);
	if (close(fd) == -1)
		ft_error(data, ft_itoa(fd), 1);
	data->high = ft_arrlen(data->map);
	ft_check_map(data);
	ft_cub(data);
	ft_free_data(data);
	exit(EXIT_SUCCESS);
}
