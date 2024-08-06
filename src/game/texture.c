/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:36:45 by nromito           #+#    #+#             */
/*   Updated: 2024/08/06 12:08:30 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

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

void	load_texture(t_cubed *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
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
		else if (!cub->texture[i].img)
			ft_error("Error: Failed to load xpm file\n", cub);
		cub->texture[i].data = (int *)mlx_get_data_addr(cub->texture[i].img,
				&cub->texture[i].bits_per_pixel, &cub->texture[i].line_len,
				&cub->texture[i].endian);
	}
}
