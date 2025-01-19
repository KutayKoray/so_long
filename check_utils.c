/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:16:51 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 02:05:49 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>	
#include "get_next_line/get_next_line.h"

void	check_exit(t_data *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x] == 'E')
	{
		if (map_data->is_all_collected)
		{
			write(1, "You win!\n", 9);
			free_data(map_data);
			exit(0);
		}
		else
		{
			write(1, "You must collect all collectables!\n", 35);
			free_data(map_data);
			exit(0);
		}
	}
	return ;
}

void	check_collected(t_data *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x] == 'C')
	{
		map_data->collectable_count--;
		map_data->map[map_data->player_y][map_data->player_x] = '0';
	}
	if (map_data->collectable_count == 0)
		map_data->is_all_collected = 1;
	return ;
}

int	can_exit(t_data *map_data, char dir)
{
	if (dir == 'd')
		if (map_data->map[map_data->player_y][map_data->player_x + 1] == 'E'
			&& map_data->collectable_count != 0)
			return (0);
	if (dir == 'a')
		if (map_data->map[map_data->player_y][map_data->player_x - 1] == 'E'
			&& map_data->collectable_count != 0)
			return (0);
	if (dir == 'w')
		if (map_data->map[map_data->player_y - 1][map_data->player_x] == 'E'
			&& map_data->collectable_count != 0)
			return (0);
	if (dir == 's')
		if (map_data->map[map_data->player_y + 1][map_data->player_x] == 'E'
			&& map_data->collectable_count != 0)
			return (0);
	return (1);
}

int	check_wall(t_data *map_data, char dir)
{
	if (dir == 'd')
	{
		if (map_data->map[map_data->player_y][map_data->player_x + 1] != '1')
			return (check_collected(map_data), can_exit(map_data, dir));
	}
	else if (dir == 'a')
	{
		if (map_data->map[map_data->player_y][map_data->player_x - 1] != '1')
			return (check_collected(map_data), can_exit(map_data, dir));
	}
	else if (dir == 'w')
	{
		if (map_data->map[map_data->player_y - 1][map_data->player_x] != '1')
			return (check_collected(map_data), can_exit(map_data, dir));
	}
	else if (dir == 's')
	{
		if (map_data->map[map_data->player_y + 1][map_data->player_x] != '1')
			return (check_collected(map_data), can_exit(map_data, dir));
	}
	return (0);
}

void init_map_data(t_data *map_data)
{
	map_data->collectable_count = 0;
	map_data->is_all_collected = 0;
	map_data->map_width = 0;
	map_data->map_height = 0;
	map_data->img_width = 0;
	map_data->img_height = 0;
	map_data->map = NULL;
	map_data->mlx = NULL;
	map_data->window = NULL;
	map_data->wall = NULL;
	map_data->road = NULL;
	map_data->collect = NULL;
	map_data->player = NULL;
	map_data->exit = NULL;
	map_data->player_x = 0;
	map_data->player_y = 0;
	map_data->number_of_moves = 0;
}
