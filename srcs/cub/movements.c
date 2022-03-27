/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:35:50 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/03/27 17:47:25 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub.h"

void	move_a(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x - raycast->plane_x * 0.11f)] != '1')
		raycast->pos_x -= raycast->plane_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y - raycast->plane_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y -= raycast->plane_y * raycast->move_speed;
}

void	move_d(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x + raycast->plane_x * 0.11f)] != '1')
		raycast->pos_x += raycast->plane_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y + raycast->plane_y * 0.11f)]
		[(int)(raycast->pos_x)] != '1')
		raycast->pos_y += raycast->plane_y * raycast->move_speed;
}

void	move_s(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x - raycast->dir_x * 0.11f)] != '1')
		raycast->pos_x -= raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y - raycast->dir_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y -= raycast->dir_y * raycast->move_speed;
}

void	move_w(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x + raycast->dir_x * 0.11f)] != '1')
		raycast->pos_x += raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y + raycast->dir_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y += raycast->dir_y * raycast->move_speed;
}
