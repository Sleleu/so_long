/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:35 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 18:50:16 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_win, vars->mlx);
	exit (0);
}
/*
void	move_W(t_vars *vars)
{
	
}*/

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_game(vars);
	if (keycode == KEY_W)
		move_W(vars);
	printf("%d", keycode);
	return (0);
}

/*
void	move_W(t_game *game)
{
	
}*/

void	ft_game(char **map_tab, t_img *img, t_vars *vars, t_map map_content)
{
		mlx_key_hook(vars->mlx_win, key_hook, &vars);
		//mlx_hook(vars->mlx_win, 2, 1L<<0, close_game, &vars);
}