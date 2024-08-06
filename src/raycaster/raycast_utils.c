/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:02:43 by ciusca            #+#    #+#             */
/*   Updated: 2024/08/06 11:56:14 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	call_wall(t_cubed *cubed, t_wall *wall, t_raycast *ray, int flag)
{
	t_player	*p;
	double		corrected_dist;

	p = cubed->player;
	corrected_dist = wall->final_dist * cos(ray->ray_angle - p->angle);
	wall->wall_height = (TILE_SIZE * HEIGHT) / corrected_dist;
	wall->wall_top = (HEIGHT / 2) - (wall->wall_height / 2);
	if (wall->wall_top < 0)
		wall->wall_top = 0;
	wall->wall_bottom = wall->wall_top + wall->wall_height;
	if (wall->wall_bottom > HEIGHT)
		wall->wall_bottom = HEIGHT;
	draw_vertical_line(cubed, 0, wall->wall_top, cubed->game->ceiling_cl);
	draw_vertical_line(cubed, wall->wall_bottom, HEIGHT, cubed->game->floor_cl);
	draw_walls(cubed, wall, flag);
}

void	angle_ray(t_raycast *ray, t_player *p)
{
	ray->ray_angle = p->angle + atan((ray->r - ray->half_screen)
			/ ray->half_screen * tan(ray->half_fov));
	ray->ray_angle = fmod(ray->ray_angle + 2 * PI, 2 * PI);
	ray->ra = ray->ray_angle;
	ray->dof = 0;
	ray->a_tan = -1 / tan(ray->ra);
}
