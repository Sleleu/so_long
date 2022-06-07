/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:18:02 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 23:18:51 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_init_img(t_map *map)
{
	//t_img	*img;
	int		img_width;
	int		img_height;

	map->char_back = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_back.xpm", &img_width, &img_height);
	map->char_front = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_front.xpm", &img_width, &img_height);
	map->char_left = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_left.xpm", &img_width, &img_height);
	map->char_right = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_right.xpm", &img_width, &img_height);
	map->tree = mlx_xpm_file_to_image
		(map->mlx, "xpm/tree.xpm", &img_width, &img_height);
	map->ground = mlx_xpm_file_to_image
		(map->mlx, "xpm/ground.xpm", &img_width, &img_height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "xpm/exit.xpm", &img_width, &img_height);
	map->berry = mlx_xpm_file_to_image
		(map->mlx, "xpm/berry.xpm", &img_width, &img_height);
	//return (img);
}

void	ft_set_item(/*t_img *img, */t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->berry, pos.x * 24, pos.y * 24);
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

void	ft_set_img(/*t_img *img, */t_map *map)
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
				ft_set_item(/*img, */map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(t_map *map)
{
//	t_img	*img;

	map->mlx = mlx_init(); // free si NULL / env -i ./so_long
	map->mlx_win = mlx_new_window(map->mlx, (map->width * 24),
			(map->height * 24), "so_long");
	/*img = */ft_init_img(map);
	ft_set_img(/*img, */map);
	ft_game(/*img, */map);
	mlx_loop(map->mlx);
}
