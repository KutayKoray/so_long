/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:16:51 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/13 15:43:34 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h> // silenecek

void	check_exit(t_data *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x] == 'E')
	{
		if (map_data->is_all_collected)
		{
			printf("You win!\n");
			free_data(map_data);
			exit(0);
		}
		else
			printf("You need to collect all collectables!\n");
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
	printf("Collectable count: %d\n", map_data->collectable_count);
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
