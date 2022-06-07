/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:35 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 17:26:55 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_end_game(t_vars *vars)
{
	mlx_destroy_window(vars.mlx, vars.mlx_win);
	return (0);
}

void	move_W(t_game *game)
{
	
}

void	ft_game(char **map_tab, t_game *game, t_vars *vars, t_map map_content)
{
	
}