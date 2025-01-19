/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:00:51 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 00:41:44 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	destroy_mlx_images(t_data *map_data)
{
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
}

void	free_data(t_data *map_data)
{
	int	i;

	i = 0;
	while (map_data->map[i])
	{
		free(map_data->map[i]);
		i++;
	}
	if (map_data->map)
		free(map_data->map);
	destroy_mlx_images(map_data);
	if (map_data->window)
		mlx_destroy_window(map_data->mlx, map_data->window);
	if (map_data->mlx)
		mlx_destroy_display(map_data->mlx);
	if (map_data->mlx)
		free(map_data->mlx);
	free(map_data);
}

void	print_error_exit(char *error_message, t_map *map_info)
{
	write(1, error_message, ft_strlen(error_message));
	if (map_info)
		free_map_info(map_info);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_info(t_map *map_info)
{
	free_map(map_info->map);
	free(map_info);
}
