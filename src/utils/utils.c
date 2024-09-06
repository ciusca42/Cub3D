/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:58:47 by nromito           #+#    #+#             */
/*   Updated: 2024/09/06 12:03:08 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

time_t	get_curr_time(time_t initial_time)
{
	time_t	curr_time;

	time(&curr_time);
	return (curr_time - initial_time);
}

int	on_click(int m_key, int x, int y,  t_cubed *cubed)
{
	(void)x;
	(void)y;
	//printf("hello im pressed\n");
	//printf("%p\n", cubed->player);
	if (cubed->keys->mouse_l == 0)
		cubed->start_shoot = get_time();
	if (m_key == 1)
		cubed->keys->mouse_l = 1;
	else if (m_key == 3)
		cubed->keys->mouse_r = 1;
	return (1);	
}

void	mask_manager(t_cubed *cubed)
{
	
	mlx_hook(cubed->win, ButtonPress, ButtonPressMask, &on_click, cubed);
	mlx_hook(cubed->win, KeyPress, KeyPressMask, &key_press, cubed->keys);
	mlx_hook(cubed->win, KeyRelease, KeyReleaseMask, &key_release, cubed->keys);
	mlx_hook(cubed->win, DestroyNotify, StructureNotifyMask, &ft_close, cubed);
	//mlx_mouse_hook(cubed->win, &mouse_press, cubed);
}

void	draw_shape(t_img *img, double x, double y, int size)
{
	int	i;
	int	j;
	int	start_x;

	start_x = x;
	j = -1;
	while (++j < size)
	{
		i = -1;
		x = start_x;
		while (++i < size)
		{
			better_pixel_put(img, x, y, rich_black);
			x++;
		}
		y++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	better_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	if (offset < 0 || offset > WIDTH * HEIGHT * 4)
		return ;
	*((unsigned int *)(offset + img->pixel_ptr)) = color;
}
