/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:32:47 by ciusca            #+#    #+#             */
/*   Updated: 2024/09/06 09:52:02 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cubed.h"

void	animate_weapon(t_cubed *cubed)
{
	t_keys		*key;
	static int	state = 1;
	int			add;
	long long	elapsed;

	elapsed = get_time() - cubed->initial_time;
	add = 1;
	key = cubed->keys;
	if (!state)
		add = -1;
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
	t_img	*weapon;
	int		i;
	int		j;

	animate_weapon(cubed);
	weapon = &cubed->weapon[0];
	weapon->data = (int *)mlx_get_data_addr(weapon->img,
			&weapon->bits_per_pixel, &weapon->line_len, &weapon->endian);
	i = -1;
	while (++i < weapon->h)
	{
		j = -1;
		while (++j < weapon->w)
		{
			if (weapon->data[i * weapon->line_len / 4 + j] != (int)0x980088)
				better_pixel_put(cubed->img, j + WIDTH / 2 - 227, i + cubed->gui->weapon_y,
					weapon->data[i * weapon->line_len / 4 + j]);
		}
	}
}
