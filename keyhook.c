/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:13:03 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/13 16:23:21 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h> // silenecek

void	key_hook_d(t_data *map_data)
{
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road,
		map_data->player_x * 100, map_data->player_y * 100);
	map_data->player_x++;
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player,
		map_data->player_x * 100, map_data->player_y * 100);
	check_exit(map_data);
}

void	key_hook_a(t_data *map_data)
{
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road,
		map_data->player_x * 100, map_data->player_y * 100);
	map_data->player_x--;
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player,
		map_data->player_x * 100, map_data->player_y * 100);
	check_exit(map_data);
}

void	key_hook_w(t_data *map_data)
{
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road,
		map_data->player_x * 100, map_data->player_y * 100);
	map_data->player_y--;
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player,
		map_data->player_x * 100, map_data->player_y * 100);
	check_exit(map_data);
}

void	key_hook_s(t_data *map_data)
{
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road,
		map_data->player_x * 100, map_data->player_y * 100);
	map_data->player_y++;
	mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player,
		map_data->player_x * 100, map_data->player_y * 100);
	check_exit(map_data);
}

void	key_hook_e(t_data *map_data)
{
	mlx_loop_end(map_data->mlx);
	free_data(map_data);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*map_data;

	map_data = (t_data *)param;
	if (keycode == 100 && check_wall(map_data, 'd'))
		key_hook_d(map_data);
	else if (keycode == 97 && check_wall(map_data, 'a'))
		key_hook_a(map_data);
	else if (keycode == 119 && check_wall(map_data, 'w'))
		key_hook_w(map_data);
	else if (keycode == 115 && check_wall(map_data, 's'))
		key_hook_s(map_data);
	else if (keycode == 65307)
		key_hook_e(map_data);
	map_data->number_of_moves++;
	printf("Number of moves: %d\n", map_data->number_of_moves); // silenecek
	return (0);
}
