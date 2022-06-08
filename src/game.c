/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:35 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/08 18:32:52 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	close_game(t_map *map)
{
	mlx_destroy_window(map->mlx_win, map->mlx);
	exit (0);
}

void	check_item(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'C')
		map->get_c++;
}

int	check_exit(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'E')
	{
		if (map->nb_c == map->get_c)
		{
			ft_printf("\nYou won !\n");
			close_game(map);
		}
		else
			return (1);
	}
	return (0);
}

void	ft_game(t_map *map)
{
	map->nb_move = 0;
	map->get_c = 0;
	mlx_key_hook(map->mlx_win, key_hook, map);
}
