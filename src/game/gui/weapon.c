/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:32:47 by ciusca            #+#    #+#             */
/*   Updated: 2024/09/06 15:32:44 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cubed.h"

void	shoot_animation(t_cubed *cubed, long long elapsed)
{
	static int 	frame = 0;
    static long long last_update = 0;
    const long long fast_frame_duration = 1;
    const long long normal_frame_duration = 50;
	long long frame_duration;

    if (!cubed->keys->mouse_l)
    {
        cubed->curr_gun = &cubed->gun[0];
        frame = 0;
        last_update = elapsed;
        return;
    }
    if (frame == 0 && last_update == 0)
        last_update = elapsed;
    frame_duration = (frame < 2) ? fast_frame_duration : normal_frame_duration;
    if (elapsed - last_update >= frame_duration)
    {
        cubed->curr_gun = &cubed->gun[frame];
        frame++;
        if (frame >= 4)
        {
            frame = 0; 
            cubed->keys->mouse_l = 0;
        }
        last_update = elapsed;
    }
}


void	animate_weapon(t_cubed *cubed)
{
	t_keys		*key;
	static int	state = 1;
	int			add;
	long long	elapsed;

	elapsed = get_time() - cubed->initial_time;
	shoot_animation(cubed, elapsed);
	add = 1;
	key = cubed->keys;
	if (!state)
		add = -1;
	if (cubed->keys->mouse_l == 1)
		return ;
	if ((key->w || key->s || key->a || key->d) && elapsed % 3)
		cubed->gui->weapon_y += add;
	else if (elapsed % 10 == 0 || elapsed % 10 == 5)
		cubed->gui->weapon_y += add;
	if (cubed->gui->weapon_y >= 90)
		state = 0;
	if (cubed->gui->weapon_y <= 70)
		state = 1;
}

void	show_weapon(t_cubed *cubed)
{
	t_img	*gun;
	int		i;
	int		j;

	animate_weapon(cubed);
	gun = cubed->curr_gun;
	i = -1;
	while (++i < gun->h)
	{
		j = -1;
		while (++j < gun->w)
		{
			if (gun->data[i * gun->line_len / 4 + j] != (int)0x980088)
				better_pixel_put(cubed->img, j + WIDTH / 2 - 227, i + cubed->gui->weapon_y,
					gun->data[i * gun->line_len / 4 + j]);
		}
	}
}
