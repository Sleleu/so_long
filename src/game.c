/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:35 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 23:07:27 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	close_game(t_map *map)
{
	mlx_destroy_window(map->mlx_win, map->mlx);
	exit (0);
}

void	set_ground(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->ground, x * 24, y * 24);
	map->map_tab[map->p_y][map->p_x] = '0';
}

void	check_item(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'C')
	{
		map->get_c++;
		printf("C gagnes %d", map->get_c);
	}
	
}

void	move_W(t_map *map)
{
	if (map->map_tab[map->p_y - 1][map->p_x] != '1')
	{
		map->p_y--;
		check_item(map, map->p_y, map->p_x);
		set_ground(map, map->p_y + 1, map->p_x);
			map->nb_move++;
			ft_printf("%d moves\n", map->nb_move);
	}
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_back, map->p_x * 24, map->p_y * 24);
}

void	move_D(t_map *map)
{
	if (map->map_tab[map->p_y][map->p_x + 1] != '1')
	{
		map->p_x++;
		check_item(map, map->p_y, map->p_x);
		set_ground(map, map->p_y, map->p_x - 1);
			map->nb_move++;
			ft_printf("%d moves\n", map->nb_move);
	}
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, map->p_x * 24, map->p_y * 24);
}

void	move_S(t_map *map)
{
	if (map->map_tab[map->p_y + 1][map->p_x] != '1')
	{
		map->p_y++;
		check_item(map, map->p_y, map->p_x);
		set_ground(map, map->p_y - 1, map->p_x);
			map->nb_move++;
			ft_printf("%d moves\n", map->nb_move);
	}
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_front, map->p_x * 24, map->p_y * 24);
}

void	move_A(t_map *map)
{
	if (map->map_tab[map->p_y][map->p_x - 1] != '1')
	{
		map->p_x--;
		check_item(map, map->p_y, map->p_x);
		set_ground(map, map->p_y, map->p_x + 1);
			map->nb_move++;
			ft_printf("%d moves\n", map->nb_move);
	}
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_left, map->p_x * 24, map->p_y * 24);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	if (keycode == KEY_W)
		move_W(map);
	if (keycode == KEY_D)
		move_D(map);
	if (keycode == KEY_S)
		move_S(map);
	if (keycode == KEY_A)
		move_A(map);
	return (0);
}

void	ft_game(/*t_img *img, */t_map *map)
{
	map->nb_move = 0;
	map->get_c = 0;
	mlx_key_hook(map->mlx_win, key_hook, map);
}