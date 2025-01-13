/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:50 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/13 15:03:07 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_coordinates;

typedef struct s_data
{
	int		collectable_count;
	int		is_all_collected;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	char	**map;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*road;
	void	*collect;
	void	*player;
	void	*exit;
	int		player_x;
	int		player_y;
	int		number_of_moves;
}			t_data;

void		key_hook_d(t_data *map_data);
void		key_hook_a(t_data *map_data);
void		key_hook_w(t_data *map_data);
void		key_hook_s(t_data *map_data);
void		key_hook_e(t_data *map_data);
int			key_hook(int keycode, void *param);

void		check_exit(t_data *map_data);
void		check_collected(t_data *map_data);
int			can_exit(t_data *map_data, char dir);
int			check_wall(t_data *map_data, char dir);

void		mlx_image_wall(t_data *map_data);
void		mlx_image_road(t_data *map_data);
void		mlx_image_collect(t_data *map_data);
void		mlx_image_player(t_data *map_data);
void		mlx_image_door(t_data *map_data);

void		free_data(t_data *map_data);

#endif
