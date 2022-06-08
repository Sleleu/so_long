/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:18:02 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/08 19:39:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_init_img(t_map *map)
{
	int		img_width;
	int		img_height;

	map->char_back = mlx_xpm_file_to_image
		(map->mlx, "xpm/char_back.xpm", &img_width, &img_height);
	map->char_front = mlx_xpm_file_to_image
		(map->mlx, "xpm/char_front.xpm", &img_width, &img_height);
	map->char_left = mlx_xpm_file_to_image
		(map->mlx, "xpm/char_left.xpm", &img_width, &img_height);
	map->char_right = mlx_xpm_file_to_image
		(map->mlx, "xpm/char_right.xpm", &img_width, &img_height);
	map->tree = mlx_xpm_file_to_image
		(map->mlx, "xpm/tree.xpm", &img_width, &img_height);
	map->ground = mlx_xpm_file_to_image
		(map->mlx, "xpm/ground.xpm", &img_width, &img_height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "xpm/exit.xpm", &img_width, &img_height);
	map->berry = mlx_xpm_file_to_image
		(map->mlx, "xpm/berry.xpm", &img_width, &img_height);
	map->berry2 = mlx_xpm_file_to_image
		(map->mlx, "xpm/berry2.xpm", &img_width, &img_height);
}

void	ft_set_item(t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
	{
		if ((pos.y * pos.x) % 2 == 0)
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->berry, pos.x * 24, pos.y * 24);
		else
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->berry2, pos.x * 24, pos.y * 24);
	}
	else if (map->map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->exit, pos.x * 24, pos.y * 24);
	else if (map->map_tab[pos.y][pos.x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, pos.x * 24, pos.y * 24);
		map->p_x = pos.x;
		map->p_y = pos.y;
	}
}

void	ft_set_img(t_map *map)
{
	t_pos	pos;

	pos.y = 0;
	while (map->map_tab[pos.y])
	{
		pos.x = 0;
		while (map->map_tab[pos.y][pos.x])
		{
			if (map->map_tab[pos.y][pos.x] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->tree, pos.x * 24, pos.y * 24);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->ground, pos.x * 24, pos.y * 24);
				ft_set_item(map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free(map->mlx);
		return ;
	}
	map->mlx_win = mlx_new_window(map->mlx, (map->width * 24),
			(map->height * 24), "so_long");
	ft_init_img(map);
	ft_set_img(map);
	ft_game(map);
	mlx_loop(map->mlx);
}
