/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:02 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 14:20:28 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	mlx_image_wall(t_data *map_data)
{
	map_data->wall = mlx_xpm_file_to_image(map_data->mlx, "textures/wall.xpm",
			&map_data->img_width, &map_data->img_height);
	if (!map_data->wall)
	{
		free_data(map_data);
		print_error_exit("Error. Wall image not found\n", NULL);
		exit(0);
	}
}

void	mlx_image_road(t_data *map_data)
{
	map_data->road = mlx_xpm_file_to_image(map_data->mlx, "textures/road.xpm",
			&map_data->img_width, &map_data->img_height);
	if (!map_data->road)
	{
		free_data(map_data);
		print_error_exit("Error. Road image not found\n", NULL);
		exit(0);
	}
}

void	mlx_image_collect(t_data *map_data)
{
	map_data->collect = mlx_xpm_file_to_image(map_data->mlx,
			"textures/collect.xpm", &map_data->img_width,
			&map_data->img_height);
	if (!map_data->collect)
	{
		free_data(map_data);
		print_error_exit("Error. Collectible image not found\n", NULL);
		exit(0);
	}
}

void	mlx_image_player(t_data *map_data)
{
	map_data->player = mlx_xpm_file_to_image(map_data->mlx,
			"textures/player.xpm", &map_data->img_width, &map_data->img_height);
	if (!map_data->player)
	{
		free_data(map_data);
		print_error_exit("Error. Player image not found\n", NULL);
		exit(0);
	}
}

void	mlx_image_door(t_data *map_data)
{
	map_data->exit = mlx_xpm_file_to_image(map_data->mlx, "textures/door.xpm",
			&map_data->img_width, &map_data->img_height);
	if (!map_data->exit)
	{
		free_data(map_data);
		print_error_exit("Error. Exit image not found\n", NULL);
		exit(0);
	}
}
