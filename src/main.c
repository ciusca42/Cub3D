/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:47:46 by nromito           #+#    #+#             */
/*   Updated: 2024/08/06 19:29:20 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include <time.h>

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	if (!parsing(argv, argc, &cubed))
		return (1);
	init_data(&cubed);
	load_texture(&cubed);
	mlx_mouse_hide(cubed.mlx, cubed.win);
	time(&cubed.time);
	mlx_mouse_move(cubed.mlx, cubed.win, WIDTH / 2, HEIGHT / 2);
	mask_manager(&cubed);
	mlx_loop_hook(cubed.mlx, &game_loop, &cubed);
	mlx_loop(cubed.mlx);
}
