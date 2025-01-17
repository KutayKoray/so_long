/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 02:06:47 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/18 02:10:03 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_map_height(char **argv)
{
	int		fd;
	char	*line;
	int		map_height;

	map_height = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_height++;
		free(line);
	}
	close(fd);
	return (map_height);
}

char	**read_map(char **argv)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (get_map_height(argv) + 1));
	if (!map)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	check_top_bottom_walls(t_map *map_info)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(map_info->map[0]) - 1;
	height = 0;
	while (map_info->map[height])
		height++;
	while (i < width)
	{
		if (map_info->map[0][i] != '1' || map_info->map[height - 1][i] != '1')
			print_error_exit("Error. Map must be surrounded by walls\n",
				map_info);
		i++;
	}
}

void	check_left_right_walls(t_map *map_info)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = 0;
	width = ft_strlen(map_info->map[0]) - 1;
	while (map_info->map[height])
		height++;
	while (i < height)
	{
		if (map_info->map[i][0] != '1' || map_info->map[i][width - 1] != '1')
			print_error_exit("Error. Map must be surrounded by walls\n",
				map_info);
		i++;
	}
}

void	check_surrounded_by_walls(t_map *map_info)
{
	check_top_bottom_walls(map_info);
	check_left_right_walls(map_info);
}
