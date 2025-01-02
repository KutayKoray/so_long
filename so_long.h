/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:50 by kkoray            #+#    #+#             */
/*   Updated: 2025/01/02 14:54:30 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data {
    int x;
    int y;
    int map_width;
    int map_height;
    char **map;
    void *mlx;
    void *window;
    void *wall;
    void *road;
    void *collect;
    void *player;
    void *exit;
    int player_x;
    int player_y;
} t_data;

#endif
