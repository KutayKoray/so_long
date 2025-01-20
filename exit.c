/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:13:59 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 14:18:06 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	error_exit(t_data *map_data)
{
	destroy_mlx_images(map_data);
	if (map_data->window)
		mlx_destroy_window(map_data->mlx, map_data->window);
	if (map_data->mlx)
	{
		mlx_loop_end(map_data->mlx);
		mlx_destroy_display(map_data->mlx);
		free(map_data->mlx);
	}
	if (map_data->map)
		free_map(map_data->map);
	free(map_data);
	print_error_exit("Error\n", NULL);
	exit(0);
}

int	correct_exit(t_data *map_data)
{
	destroy_mlx_images(map_data);
	if (map_data->window)
		mlx_destroy_window(map_data->mlx, map_data->window);
	if (map_data->mlx)
	{
		mlx_loop_end(map_data->mlx);
		mlx_destroy_display(map_data->mlx);
	}
	free(map_data->mlx);
	free_map(map_data->map);
	free(map_data);
	exit(-1);
	return (0);
}
