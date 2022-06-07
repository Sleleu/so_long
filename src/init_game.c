/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:18:02 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 22:40:18 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

t_img	*ft_init_img(/*char **map_tab, */t_map *map)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img->char_back = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_back.xpm", &img_width, &img_height);
	img->char_front = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_front.xpm", &img_width, &img_height);
	img->char_left = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_left.xpm", &img_width, &img_height);
	img->char_right = mlx_xpm_file_to_image
		(map->mlx, "xpm/charmander_right.xpm", &img_width, &img_height);
	img->tree = mlx_xpm_file_to_image
		(map->mlx, "xpm/tree.xpm", &img_width, &img_height);
	img->ground = mlx_xpm_file_to_image
		(map->mlx, "xpm/ground.xpm", &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image
		(map->mlx, "xpm/exit.xpm", &img_width, &img_height);
	img->berry = mlx_xpm_file_to_image
		(map->mlx, "xpm/berry.xpm", &img_width, &img_height);
	return (img);
}

void	ft_set_item(/*char **map_tab, */t_img *img, t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			img->berry, pos.x * 24, pos.y * 24);
	else if (map->map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			img->exit, pos.x * 24, pos.y * 24);
//	else if (map_tab[pos.y][pos.x] == 'P')
//		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
//			game->char_right, pos.x * 24, pos.y * 24);
}

void	ft_set_img(/*char **map_tab, */t_img *img, t_map *map)
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
					img->tree, pos.x * 24, pos.y * 24);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					img->ground, pos.x * 24, pos.y * 24);
				ft_set_item(/*map_tab, */img, map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(/*char **map_tab, */t_map *map)
{
	t_img	*img;
	//t_map	map_content;
	//t_map	*map;
	void	*mlx;
	void	*mlx_win;

	//map->mlx = mlx;
	//map->mlx_win = mlx_win;
	//map_content = ft_get_map_stat(map_tab, map_content);
	map->mlx = mlx_init(); // free si NULL / env -i ./so_long
	map->mlx_win = mlx_new_window(map->mlx, (map->width * 24),
			(map->height * 24), "so_long");
	img = ft_init_img(/*map_tab, */map);
	ft_set_img(/*map_tab, */img, map);
	ft_game(/*map_tab, */img, map);
	mlx_loop(map->mlx);
}
