/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 02:20:52 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/18 02:24:17 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

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
