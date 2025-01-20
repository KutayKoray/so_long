/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:13:03 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/20 14:19:14 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

int	exit_from_window(t_data *map_data)
{
	mlx_loop_end(map_data->mlx);
	free_data(map_data);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*map_data;

	map_data = (t_data *)param;
	if (keycode == 100 && check_wall(map_data, 'd'))
		key_hook_d(map_data);
	else if (keycode == 97 && check_wall(map_data, 'a'))
		key_hook_a(map_data);
	else if (keycode == 119 && check_wall(map_data, 'w'))
		key_hook_w(map_data);
	else if (keycode == 115 && check_wall(map_data, 's'))
		key_hook_s(map_data);
	else if (keycode == 65307)
		key_hook_e(map_data);
	if ((keycode == 100 && check_wall(map_data, 'd')) || (keycode == 97
			&& check_wall(map_data, 'a')) || (keycode == 119
			&& check_wall(map_data, 'w')) || (keycode == 115
			&& check_wall(map_data, 's')))
	{
		map_data->number_of_moves++;
		ft_printf("Number of moves: %d\n", map_data->number_of_moves);
	}
	return (0);
}
