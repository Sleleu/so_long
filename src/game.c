/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:35 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 22:40:42 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	close_game(t_map *map)
{
	mlx_destroy_window(map->mlx_win, map->mlx);
	exit (0);
}
/*
void	move_W(t_vars *vars)
{
	
}*/

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
//	if (keycode == KEY_W)
//		move_W(vars);
	printf("%d", keycode);
	return (0);
}

/*
void	move_W(t_game *game)
{
	
}*/

void	ft_game(/*char **map_tab, */t_img *img, t_map *map)
{
		mlx_key_hook(map->mlx_win, key_hook, &map);
		//mlx_hook(vars->mlx_win, 2, 1L<<0, close_game, &vars);
}