/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:16:21 by nromito           #+#    #+#             */
/*   Updated: 2024/09/06 11:46:48 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include "defines.h"
# include "structs.h"
# include "errors.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>

/* ------------------------ */
/*          INDEX           */	
/* ------------------------ */
/* 1. INIT    	line: (44)  */
/* 2. GAME   	line: (51)  */
/* 3. MOVEMENT	line: (61)  */
/* 4. SETTINGS  line: (70)*/
/* 5. KEYS    	line: (79)  */
/* 6. PARSING 	line: (88)  */
/* 7. TEXTURE 	line: (97)  */
/* 8. CLOSE   	line: (106) */
/* 9. UTILS   	line: (115) */

/**======================
 *?    		INIT
 *========================**/
int		init_data(t_cubed *cubed);
int		partial_init(t_cubed *cubed);
void	create_img(void *mlx, t_img *img);

/**======================
 *?    		GAME
 *========================**/
int		game_loop(t_cubed *cub);
int		is_door(t_cubed *cubed, int map_x, int map_y);
void	draw_walls(t_cubed *cubed, t_wall *wall, int flag);
void	draw_vertical_line(t_cubed *cubed, int start, int end, int color);
void	rendering(t_cubed *cubed);
void	minimap(t_cubed *cubed);
void	interactable(t_cubed *cubed);
int		calculate_dir(t_raycast *ray, t_player *p, double *f_dist, int flag);
void	calculate_ver(t_raycast *ray, t_player *p);
void	calculate_hor(t_cubed *cubed, t_raycast *ray);
void	call_door_wall(t_cubed *cubed, t_wall *wall, t_raycast *ray, int flag);
void	call_wall(t_cubed *cubed, t_wall *wall, t_raycast *ray, int flag);
void	ver_loop(t_cubed *cubed, t_raycast *ray, int flag);
void	hor_loop(t_cubed *cubed, t_raycast *ray, int flag);
void	angle_ray(t_raycast *ray, t_player *p);

/**======================
 *?    	 MOVEMENT
 *========================**/
void	move_up(t_cubed *cubed, double dist);
void	move_down(t_cubed *cubed, double dist);
void	move_left(t_cubed *cubed, double dist);
void	move_right(t_cubed *cubed, double dist);
int		rotate_player(t_cubed *cubed, t_keys *key);

/**======================
 *?     CHANGE SETTINGS
 *========================**/
void	change_fov(t_cubed *cubed);
void	player_run(t_cubed *cubed);
int		mouse_rotate_pov(t_cubed *cubed);
int		check_map_size(t_cubed *cubed);

/**======================
 *?    INPUT MANAGER
 *========================**/
int		settings_handler(t_cubed *cubed);

/**======================
 *?    		KEYS
 *========================**/
int		key_press(int pressed, t_keys *keys);
int		key_release(int realesed, t_keys *keys);

/**======================
 *?    	  	GUI
 *========================**/
void	draw_crosshair(t_cubed *cubed);
void	draw_minimap(t_cubed *cubed);
void	minimap(t_cubed *cubed);
void	text_gui(t_cubed *cubed);
void	draw_background(t_img *img);
void	show_weapon(t_cubed *cubed);

/**======================
 *?    	  PARSING
 *========================**/
int		parsing(char **argv, int argc, t_cubed *cubed);
int		check_file(char *map, t_cubed *cubed);
int		count_map_columns(int fd, t_cubed *cubed);
int		count_width(t_cubed *cubed);
int		check_chars(char **map, int l, int col);
void	check_map(t_cubed *cubed);
int		surfaces_check(char *line, t_cubed *cubed);
int		textures_check(char *line, t_cubed *cubed);
int		check_colors(char **color, t_cubed *cubed, int surface);
int		is_double_player(t_cubed *cubed, int *flag, int rows, int col);
int		syntax_checker(t_cubed *cubed);
void	set_player(t_cubed *cubed, char c);
int		count_commas(char *line);
int		is_acceptable(char c);
int		is_texture(t_cubed *cubed, int i, int k);
int		is_legal(char c);

/**======================
 *?    	  TEXTURE
 *========================**/
void	load_texture(t_cubed *cubed);

/**======================
 *?    	CLOSE / ERROR
 *========================**/
int		ft_close(t_cubed *cubed, int err_status);
int		ft_error(char *error, t_cubed *cubed);

int	on_click(int m_key, int x, int y, t_cubed *cubed);

/**======================
 *?    		UTILS
 *========================**/
void	draw_shape(t_img *img, double x, double y, int size);
int		is_wall(t_cubed *cubed, double x, double y);
int		create_trgb(int t, int r, int g, int b);
void	draw_line(t_img *img, int start_pos[2], int x1, int y1);
void	better_pixel_put(t_img *img, int x, int y, int color);
int		validate_position(t_cubed *cubed, double dist, double dir);
clock_t	get_curr_time(time_t initial_time);
void	mask_manager(t_cubed *cubed);
void	error_msg(t_cubed *cubed, char *msg, char **matrix);
long long get_time();

#endif