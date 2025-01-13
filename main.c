/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:02 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/14 00:51:01 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "minilibx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h> // kaldır
#include <stdlib.h>
#include <unistd.h>

t_data	*map_create(char **argv)
{
	int		fd;
	char	*line;
	t_data	*map_data;

	fd = open(argv[1], O_RDONLY);
	map_data = ft_calloc(1, sizeof(t_data));
	if (!map_data)
		return (NULL);
	map_data->map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_data->map_height++;
		map_data->map_width = ft_strlen(line);
		free(line);
	}
	close(fd);
	return (map_data);
}

void	put_windows(t_data *map_data, char *line, int i, int j)
{
	if (line[j] == '1')
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->wall,
			j * 100, i * 100);
	else if (line[j] == 'P')
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window,
			map_data->player, j * 100, i * 100);
		map_data->player_x = j;
		map_data->player_y = i;
	}
	else if (line[j] == 'C')
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window,
			map_data->collect, j * 100, i * 100);
		map_data->collectable_count++;
	}
	else if (line[j] == 'E')
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->exit,
			j * 100, i * 100);
	else
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road,
			j * 100, i * 100);
}

void	map_fill(t_data *map_data, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = 0;
		while (line[j])
		{
			put_windows(map_data, line, i, j);
			j++;
		}
		map_data->map[i] = line;
		i++;
	}
	close(fd);
}

void mlx_renders(t_data *map_data)
{
	map_data->img_width = 100;
	map_data->img_height = 100;
	map_data->mlx = mlx_init();
	if (!map_data->mlx)
		exit(0);
	map_data->window = mlx_new_window(map_data->mlx, map_data->map_width * 100,
			map_data->map_height * 100, "test-deneme");
	if (!map_data->window)
		exit(0);
	mlx_image_wall(map_data);
	mlx_image_road(map_data);
	mlx_image_collect(map_data);
	mlx_image_player(map_data);
	mlx_image_door(map_data);

}

int	main(int argc, char **argv)
{
	t_data	*map_data;

	(void)argc;
	check_dir_exist(argv);
	validate_map(argv);
	map_data = map_create(argv);
	if (!map_data)
		return (-1);
	mlx_renders(map_data);
	map_data->map = ft_calloc(map_data->map_height, sizeof(char **)); // double pointer olabilir
	map_fill(map_data, argv);
	mlx_key_hook(map_data->window, key_hook, map_data);
	mlx_loop(map_data->mlx);
	return (0);
}
