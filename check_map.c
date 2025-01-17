/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:40:16 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/18 02:19:14 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_dir_exist(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_exit("Error. Directory not exist\n", NULL);
	close(fd);
}

void	check_valid_characters(t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j] != '\0' && map_info->map[i][j] != '\n')
		{
			if (map_info->map[i][j] != '0' && map_info->map[i][j] != '1'
				&& map_info->map[i][j] != 'C' && map_info->map[i][j] != 'E'
				&& map_info->map[i][j] != 'P')
				print_error_exit("Error. unvalid characters.\n", map_info);
			j++;
		}
		i++;
	}
}

void	check_rectangular(t_map *map_info)
{
	int	i;
	int	j;
	int	line_lenght;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j] != '\n' && map_info->map[i][j] != '\0')
			j++;
		if (i == 0)
			line_lenght = j;
		else if (line_lenght != j)
			print_error_exit("Error. Map must be rectangular\n", map_info);
		i++;
	}
}

void	check_required_elements(t_map *map_info)
{
	int				i;
	int				j;
	t_char_counts	counts;

	i = 0;
	counts.exits = 0;
	counts.collectibles = 0;
	counts.players = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'E')
				counts.exits++;
			else if (map_info->map[i][j] == 'C')
				counts.collectibles++;
			else if (map_info->map[i][j] == 'P')
				counts.players++;
			j++;
		}
		i++;
	}
	if (counts.exits != 1 || counts.players != 1 || counts.collectibles < 1)
		print_error_exit("Error. unvalid char count\n", map_info);
}

void	validate_map(char **argv)
{
	t_map	*map_info;

	map_info = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map_info)
		print_error_exit("Error. Memory allocation failed\n", NULL);
	map_info->map = read_map(argv);
	map_info->map_height = get_map_height(argv);
	map_info->map_width = ft_strlen(map_info->map[0]) - 1;
	check_valid_characters(map_info);
	check_rectangular(map_info);
	check_required_elements(map_info);
	check_surrounded_by_walls(map_info);
	if (!check_valid_path(map_info))
		print_error_exit("Error. Map is not valid\n", map_info);
	free_map_info(map_info);
}
