/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:00:51 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/13 16:25:24 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

void	free_data(t_data *map_data)
{
	int i;

	i = 0;
	while (i < map_data->map_height)
	{
		free(map_data->map[i]);
		i++;
	}
	if (map_data->map)
		free(map_data->map);
	if (map_data->wall)
		mlx_destroy_image(map_data->mlx, map_data->wall);
	if (map_data->road)
		mlx_destroy_image(map_data->mlx, map_data->road);
	if (map_data->collect)
		mlx_destroy_image(map_data->mlx, map_data->collect);
	if (map_data->player)
		mlx_destroy_image(map_data->mlx, map_data->player);
	if (map_data->exit)
		mlx_destroy_image(map_data->mlx, map_data->exit);
	if (map_data->window)
		mlx_destroy_window(map_data->mlx, map_data->window);
	if (map_data->mlx)
		mlx_destroy_display(map_data->mlx);
	free(map_data);
}
