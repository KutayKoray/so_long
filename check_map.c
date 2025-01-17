// header eklenecek

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> // kaldır

void check_dir_exist(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "No file found, wrong map name\n", 31);
		exit(0);
	}
	close(fd);
}

void free_and_exit(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(0);
}

void check_valid_characters(char **map)
{
    int i;
	int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\0' && map[i][j] != '\n')
        {
            if (map[i][j] != '0' && map[i][j] != '1' &&
                map[i][j] != 'C' && map[i][j] != 'E' &&
                map[i][j] != 'P')
            {
                write(1, "Error. Invalid character in map\n", 33);
                free_and_exit(map);
				exit(0);
            }
            j++;
        }
        i++;
    }
}

void check_rectangular(char **map)
{
    int i;
	int j;
	int line_lenght;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j] != '\n' && map[i][j] != '\0')
			j++;
		if (i == 0)
			line_lenght = j;
		else if (line_lenght != j)
		{
			write(1, "Error. Map must be rectangular\n", 31);
			free_and_exit(map);
			exit(0);
		}
		i++;
	}
}

void check_required_elements(char **map)
{
    int i = 0, j;
    int exits = 0, collectibles = 0, players = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E') exits++;
            else if (map[i][j] == 'C') collectibles++;
            else if (map[i][j] == 'P') players++;
            j++;
        }
        i++;
    }
    if (exits != 1 || players != 1 || collectibles < 1)
    {
        write(1, "Error. Map must contain 1 exit, 1 player, and at least 1 collectible\n", 70);
		free_and_exit(map);
        exit(0);
    }
}
void check_top_bottom_walls(char **map)
{
    int i;
    int width;
    int height;

    i = 0;
    width = ft_strlen(map[0]) - 1;
    height = 0;
    while (map[height])
		height++;

    while (i < width)
    {
        if (map[0][i] != '1' || map[height - 1][i] != '1')
        {
            write(1, "Error. Map must be surrounded by walls\n", 40);
            free_and_exit(map);
            exit(0);
        }
        i++;
    }
}

void check_left_right_walls(char **map)
{
    int i;
    int height;
    int width;

    i = 0;
    height = 0;
	width = ft_strlen(map[0]) - 1;
    while (map[height])
		height++;

    while (i < height)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
        {
            write(1, "Error. Map must be surrounded by walls\n", 40);
            free_and_exit(map);
            exit(0);
        }
        i++;
    }
}

void check_surrounded_by_walls(char **map)
{
    check_top_bottom_walls(map);
    check_left_right_walls(map);
}

int get_map_height(char **argv)
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

char **read_map(char **argv)
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

// void check_valid_path(char **map)
// {

// }

void validate_map(char **argv)
{
	check_valid_characters(read_map(argv));
	check_rectangular(read_map(argv));
	check_required_elements(read_map(argv));
	check_surrounded_by_walls(read_map(argv));
}
