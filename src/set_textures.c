/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:54 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/08 18:33:09 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	set_char(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_back, map->p_x * 24, map->p_y * 24);
	if (keycode == KEY_S)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_front, map->p_x * 24, map->p_y * 24);
	if (keycode == KEY_A)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_left, map->p_x * 24, map->p_y * 24);
	if (keycode == KEY_D)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, map->p_x * 24, map->p_y * 24);
}

void	set_ground(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->ground, x * 24, y * 24);
	map->map_tab[map->p_y][map->p_x] = '0';
}
