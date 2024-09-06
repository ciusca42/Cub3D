/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:02:43 by ciusca            #+#    #+#             */
/*   Updated: 2024/09/06 16:13:09 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

uint32_t get_texture_pixel(t_img texture, int x, int y)
{
    // Ensure x and y are within the bounds of the texture
    if (x < 0 || x >= texture.w || y < 0 || y >= texture.h)
    {
        return 0x000000; // Return black or another fallback color in case of out-of-bounds
    }

    // Retrieve the pixel color from the texture data array
    return texture.data[y * texture.w + x];
}

void draw_ceiling_floor(t_cubed *cubed, t_wall *wall)
{
    t_player *p = cubed->player;
    t_img *textures = cubed->texture;
    t_raycast *ray = cubed->raycast;
	double ray_dir_x = cos(ray->ray_angle);
	double ray_dir_y = sin(ray->ray_angle);

    int y;

    // Draw ceiling
    for (y = 0; y < wall->wall_top; y++)
    {
        // Calculate the distance from the player to the ceiling
        double p_dist = HEIGHT / (2.0 * (y - HEIGHT / 2.0 + wall->wall_height / 2.0));

        // Calculate the world coordinates
        double world_x = p->x + p_dist * ray_dir_x;
        double world_y = p->y + p_dist * ray_dir_y;

        // Convert world coordinates to texture coordinates
        int tex_x = (int)(world_x * textures[1].w) % textures[1].w;
        int tex_y = (int)(world_y * textures[1].h) % textures[1].h;

        uint32_t ceiling_color = get_texture_pixel(textures[1], tex_x, tex_y);
        better_pixel_put(cubed->img, ray->r, y, ceiling_color);
    }

    // Draw floor
    for (y = wall->wall_bottom; y < HEIGHT; y++)
    {
        // Calculate the distance from the player to the floor
        double p_dist = HEIGHT / (2.0 * (y - HEIGHT / 2.0 + wall->wall_height / 2.0));

        // Calculate the world coordinates
        double world_x = p->x + p_dist * ray_dir_x;
        double world_y = p->y + p_dist * ray_dir_y;

        // Convert world coordinates to texture coordinates
        int tex_x = (int)(world_x * textures[1].w) % textures[1].w;
        int tex_y = (int)(world_y * textures[1].h) % textures[1].h;

        uint32_t floor_color = get_texture_pixel(textures[1], tex_x, tex_y);
        better_pixel_put(cubed->img, ray->r, y, floor_color);
    }
}




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
	//draw_ceiling_floor(cubed, wall);
	draw_walls(cubed, wall, flag);
}

void	call_door_wall(t_cubed *cubed, t_wall *wall, t_raycast *ray, int flag)
{
	int	i;
	int	j;

	i = (int)(ray->rx / TILE_SIZE);
	j = (int)(ray->ry / TILE_SIZE);
	wall->wall_top = (HEIGHT / 2) - (wall->wall_height / 2);
	wall->wall_bottom = wall->wall_top + wall->wall_height;
	if (wall->wall_bottom > HEIGHT)
		wall->wall_bottom = HEIGHT;
	if (wall->wall_top < 0)
		wall->wall_top = 0;
	if (i >= 0 && i < cubed->map_w && j >= 0 && j < cubed->game->ht
		&& is_door(cubed, i, j))
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

int	is_door(t_cubed *cubed, int map_x, int map_y)
{
	if (cubed->map[map_y][map_x] == 'D'
		|| cubed->map[map_y][map_x] == 'A')
		return (1);
	return (0);
}
