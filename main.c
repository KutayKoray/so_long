/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:02 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/11 15:34:11 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "minilibx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h> // kaldır
#include <stdlib.h>
#include <unistd.h>

void check_exit(t_data *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x] == 'E')
	{
		if (map_data->is_all_collected)
		{
			printf("You win!\n");
			mlx_destroy_window(map_data->mlx, map_data->window);
			exit(0);
		}
		else
			printf("You need to collect all collectables!\n");
	}
	return ;
}

void check_collected(t_data *map_data)
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

int can_exit(t_data *map_data, char dir)
{
	if (dir == 'd')
		if (map_data->map[map_data->player_y][map_data->player_x + 1] == 'E' && map_data->collectable_count != 0)
			return (0);
	if (dir == 'a')
		if (map_data->map[map_data->player_y][map_data->player_x - 1] == 'E' && map_data->collectable_count != 0)
			return (0);
	if (dir == 'w')
		if (map_data->map[map_data->player_y - 1][map_data->player_x] == 'E' && map_data->collectable_count != 0)
			return (0);
	if (dir == 's')
		if (map_data->map[map_data->player_y + 1][map_data->player_x] == 'E' && map_data->collectable_count != 0)
			return (0);
	return (1);
}

int check_wall(t_data *map_data, char dir)
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

int	key_hook(int keycode, void *param)
{
	t_data	*map_data;

	map_data = (t_data *)param;
	if (keycode == 2 && check_wall(map_data, 'd'))
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road, map_data->player_x * 100, map_data->player_y * 100);
		map_data->player_x++;
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player, map_data->player_x * 100, map_data->player_y * 100);
		check_exit(map_data);
	}
	else if (keycode == 0 && check_wall(map_data, 'a'))
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road, map_data->player_x * 100, map_data->player_y * 100);
		map_data->player_x--;
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player, map_data->player_x * 100, map_data->player_y * 100);
		check_exit(map_data);
	}
	else if (keycode == 13 && check_wall(map_data, 'w'))
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road, map_data->player_x * 100, map_data->player_y * 100);
		map_data->player_y--;
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player, map_data->player_x * 100, map_data->player_y * 100);
		check_exit(map_data);
	}
	else if (keycode == 1 && check_wall(map_data, 's'))
	{
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->road, map_data->player_x * 100, map_data->player_y * 100);
		map_data->player_y++;
		mlx_put_image_to_window(map_data->mlx, map_data->window, map_data->player, map_data->player_x * 100, map_data->player_y * 100);
		check_exit(map_data);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(map_data->mlx, map_data->window);
		exit(0);
	}

	map_data->number_of_moves++;
	printf("Number of moves: %d\n", map_data->number_of_moves);
	return (0);
}



int	main(int argc, char **argv)
{
	int fd;
	char *line;
	t_data *map_data;
	(void)argc;

	fd = open(argv[1], O_RDONLY);
	map_data = ft_calloc(1, sizeof(t_data));
	if (!map_data)
		return (-1);
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

	void *mlx = mlx_init();
	if (!mlx)
		return (-1);
	void *window = mlx_new_window(mlx, map_data->map_width * 100,
			map_data->map_height * 100, "test-deneme");
	if (!window)
		return (-1);
	int img_width = 100;
	int img_height = 100;
	void *wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &img_width,
			&img_height);
	if (!wall)
		return (-1);
	void *road = mlx_xpm_file_to_image(mlx, "textures/road.xpm", &img_width,
			&img_height);
	if (!road)
		return (-1);
	void *collect = mlx_xpm_file_to_image(mlx, "textures/collect.xpm",
			&img_width, &img_height);
	if (!collect)
		return (-1);
	void *player = mlx_xpm_file_to_image(mlx, "textures/player.xpm",
			&img_width, &img_height);
	if (!player)
		return (-1);
	void *exit = mlx_xpm_file_to_image(mlx, "textures/door.xpm",
			&img_width, &img_height);
	if (!exit)
		return (-1);

	map_data->mlx = mlx;
	map_data->window = window;
	map_data->wall = wall;
	map_data->road = road;
	map_data->collect = collect;
	map_data->player = player;
	map_data->exit = exit;

	int i = 0;
	int j;
	map_data->map = ft_calloc(map_data->map_height, sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = 0;
		while (line[j])
		{
			if (line[j] == '1')
			{
				mlx_put_image_to_window(mlx, window, wall, j * 100, i * 100);
			}
			else if (line[j] == 'P')
			{
				mlx_put_image_to_window(mlx, window, player, j * 100, i * 100);
				map_data->player_x = j;
				map_data->player_y = i;
			}
			else if (line[j] == 'C')
			{
				mlx_put_image_to_window(mlx, window, collect, j * 100, i * 100);
				map_data->collectable_count++;
			}
			else if (line[j] == 'E')
			{
				mlx_put_image_to_window(mlx, window, exit, j * 100, i * 100);
			}
			else
			{
				mlx_put_image_to_window(mlx, window, road, j * 100, i * 100);
			}
			j++;
		}
		map_data->map[i] = line;
		i++;
	}
	close(fd);

	mlx_key_hook(map_data->window, key_hook, map_data);
	mlx_loop(mlx);
	
	return (0);
}
