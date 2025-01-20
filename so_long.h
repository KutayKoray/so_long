/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:50 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 14:08:36 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct s_char_counts
{
	int				collectibles;
	int				exits;
	int				players;
}					t_char_counts;

typedef struct s_map
{
	char			**map;
	int				map_width;
	int				map_height;
	t_coordinates	start_coord;
	int				collected;
	int				reached_e;
	int				total_collect;
	int				collected_all_c;
}					t_map;

typedef struct s_data
{
	int				collectable_count;
	int				is_all_collected;
	int				map_width;
	int				map_height;
	int				img_width;
	int				img_height;
	char			**map;
	void			*mlx;
	void			*window;
	void			*wall;
	void			*road;
	void			*collect;
	void			*player;
	void			*exit;
	int				player_x;
	int				player_y;
	int				number_of_moves;
}					t_data;

void				init_map_data(t_data *map_data);

void				key_hook_d(t_data *map_data);
void				key_hook_a(t_data *map_data);
void				key_hook_w(t_data *map_data);
void				key_hook_s(t_data *map_data);
void				key_hook_e(t_data *map_data);
int					key_hook(int keycode, void *param);

void				check_exit(t_data *map_data);
void				check_collected(t_data *map_data);
int					can_exit(t_data *map_data, char dir);
int					check_wall(t_data *map_data, char dir);

void				mlx_image_wall(t_data *map_data);
void				mlx_image_road(t_data *map_data);
void				mlx_image_collect(t_data *map_data);
void				mlx_image_player(t_data *map_data);
void				mlx_image_door(t_data *map_data);

void				free_data(t_data *map_data);
void				free_map(char **map);
void				free_map_info(t_map *map_info);
void				error_exit(t_data *map_data);
int					correct_exit(t_data *map_data);
void				print_error_exit(char *error_message, t_map *map_info);

void				check_dir_exist(char **argv);
void				validate_map(char **map);
char				**read_map(char **argv);
int					check_valid_path(t_map *map_info);

void				destroy_mlx_images(t_data *map_data);
void				check_surrounded_by_walls(t_map *map_info);
int					get_map_height(char **argv);

void				check_extension(char **argv, t_map *map_info);
void				total_collectable(t_map *map_info);
int					exit_from_window(t_data *map_data);

#endif
