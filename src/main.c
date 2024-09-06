/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:47:46 by nromito           #+#    #+#             */
/*   Updated: 2024/09/06 11:42:49 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include <time.h>

long long get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);  // Get the current time
    return (long long)(ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL);  // Convert to milliseconds
}

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	cubed.initial_time = get_time();
	if (!parsing(argv, argc, &cubed))
		return (1);
	init_data(&cubed);
	load_texture(&cubed);
	mlx_mouse_hide(cubed.mlx, cubed.win);
	mlx_mouse_move(cubed.mlx, cubed.win, WIDTH / 2, HEIGHT / 2);
	mask_manager(&cubed);
	printf("%d\n", cubed.keys->mouse_l + 1);
	//on_click(1, &cubed);
	mlx_loop_hook(cubed.mlx, &game_loop, &cubed);
	
	mlx_loop(cubed.mlx);
}
