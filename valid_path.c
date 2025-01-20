/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:11:26 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 14:20:46 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

void	total_collectable(t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	map_info->total_collect = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'C')
				map_info->total_collect++;
			j++;
		}
		i++;
	}
}

void	check_extension(char **argv, t_map *map_info)
{
	char	*filename;
	int		len;

	filename = argv[1];
	len = 0;
	len = ft_strlen(filename);
	if (len < 5)
		print_error_exit("Error. Invalid file extension len count\n", map_info);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
			- 2] != 'e' || filename[len - 1] != 'r')
		print_error_exit("Error. Invalid file extension .ber uzantısı\n",
			map_info);
	if ((filename[len - 4] == '.' || filename[len - 3] == 'b' || filename[len
				- 2] == 'e' || filename[len - 1] == 'r') && filename[len
			- 5] == '/')
		print_error_exit("Error. Invalid file extension sadece .ber\n",
			map_info);
}

static void	find_start_position(t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->map_height)
	{
		j = 0;
		while (j < map_info->map_width)
		{
			if (map_info->map[i][j] == 'P')
			{
				map_info->start_coord.x = i;
				map_info->start_coord.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	print_error_exit("Error. Starting position not found\n", map_info);
}

static void	flood_fill(t_map *map_info, int x, int y)
{
	if (x < 0 || y < 0 || x >= map_info->map_height || y >= map_info->map_width
		|| map_info->map[x][y] == '1' || map_info->map[x][y] == 'V')
		return ;
	if (map_info->map[x][y] == 'C')
		map_info->collected++;
	if (map_info->collected == map_info->total_collect)
		map_info->collected_all_c = 1;
	if (map_info->map[x][y] == 'E')
	{
		map_info->reached_e = 1;
		return ;
	}
	map_info->map[x][y] = 'V';
	flood_fill(map_info, x + 1, y);
	flood_fill(map_info, x - 1, y);
	flood_fill(map_info, x, y + 1);
	flood_fill(map_info, x, y - 1);
}

int	check_valid_path(t_map *map_info)
{
	find_start_position(map_info);
	map_info->collected_all_c = 0;
	map_info->reached_e = 0;
	flood_fill(map_info, map_info->start_coord.x, map_info->start_coord.y);
	return (map_info->collected_all_c && map_info->reached_e);
}
