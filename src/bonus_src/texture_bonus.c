/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:36:45 by nromito           #+#    #+#             */
/*   Updated: 2024/09/06 10:56:44 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	load_gun_texture(t_cubed *cubed)
{
	int		i;
	char	*frame_num;
	char	*gun_text;
	
	i = 0;
	while (i < 4)
	{
		frame_num = ft_itoa(i);
		gun_text = ft_strjoin("src/textures/gun/pistol_", frame_num);
		free(frame_num);
		frame_num = ft_strdup(gun_text);
		free(gun_text);
		gun_text = ft_strjoin(frame_num, ".xpm");
		free(frame_num);
		printf("gun text = %s\n", gun_text);
		cubed->gun[i].img = mlx_xpm_file_to_image(cubed->mlx, gun_text,
						&cubed->gun[i].w, &cubed->gun[i].h);
		cubed->gun[i].data = (int *)mlx_get_data_addr(cubed->gun[i].img,
				&cubed->gun[i].bits_per_pixel, &cubed->gun[i].line_len,
				&cubed->gun[i].endian);
		free(gun_text);
		i++;
	}
}

char	*get_frame_path(t_img *door_anim, int i)
{
	char	*str;
	char	*door_frame;
	char	*temp;

	door_anim[i].frame = i;
	str = ft_itoa(i + 1);
	door_frame = ft_strjoin(DOOR_PATH, str);
	free(str);
	temp = ft_strdup(door_frame);
	free(door_frame);
	door_frame = ft_strjoin(temp, ".xpm");
	free(temp);
	return (door_frame);
}

void	load_door_animation(t_cubed *cubed, int curr)
{
	int		i;
	t_img	*door_anim;
	char	*door_frame;

	i = -1;
	
	load_gun_texture(cubed);
	door_anim = cubed->door_anim;
	while (++i < FRAME_NUMBER)
	{
		door_frame = get_frame_path(door_anim, i);
		door_anim[i].img = mlx_xpm_file_to_image(cubed->mlx, door_frame,
				&door_anim[i].w, &door_anim[i].h);
		if (!door_anim[i].img)
		{
			free(door_frame);
			ft_error("Error: Failed to load xpm file\n", cubed);
		}
		door_anim[i].data = (int *)mlx_get_data_addr(door_anim[i].img,
				&door_anim[i].bits_per_pixel, &door_anim[i].line_len,
				&door_anim[i].endian);
		free(door_frame);
	}
	cubed->texture[curr] = door_anim[0];
}

void	load_texture(t_cubed *cub)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (i == 0)
			cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx,
					cub->game->no, &cub->texture[i].w, &cub->texture[i].h);
		else if (i == 1)
			cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx,
					cub->game->so, &cub->texture[i].w, &cub->texture[i].h);
		else if (i == 2)
			cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx,
					cub->game->we, &cub->texture[i].w, &cub->texture[i].h);
		else if (i == 3)
			cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx,
					cub->game->ea, &cub->texture[i].w, &cub->texture[i].h);
		else if (i == 4)
			load_door_animation(cub, i);
		else if (!cub->texture[i].img)
			ft_error("Error: Failed to load xpm file\n", cub);
		cub->texture[i].data = (int *)mlx_get_data_addr(cub->texture[i].img,
				&cub->texture[i].bits_per_pixel, &cub->texture[i].line_len,
				&cub->texture[i].endian);
	}
}
