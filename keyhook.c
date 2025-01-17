/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:13:03 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/18 02:22:15 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"

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
	map_data->number_of_moves++;
	ft_printf("Number of moves: %d\n", map_data->number_of_moves);
		// duvar olunca yazmasın
	return (0);
}
