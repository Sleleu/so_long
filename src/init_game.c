/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:18:02 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 17:27:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

t_img	*ft_init_img(char **map_tab, t_vars *vars)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img->char_back = mlx_xpm_file_to_image
		(vars->mlx, "xpm/charmander_back.xpm", &img_width, &img_height);
	img->char_front = mlx_xpm_file_to_image
		(vars->mlx, "xpm/charmander_front.xpm", &img_width, &img_height);
	img->char_left = mlx_xpm_file_to_image
		(vars->mlx, "xpm/charmander_left.xpm", &img_width, &img_height);
	img->char_right = mlx_xpm_file_to_image
		(vars->mlx, "xpm/charmander_right.xpm", &img_width, &img_height);
	img->tree = mlx_xpm_file_to_image
		(vars->mlx, "xpm/tree.xpm", &img_width, &img_height);
	img->ground = mlx_xpm_file_to_image
		(vars->mlx, "xpm/ground.xpm", &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image
		(vars->mlx, "xpm/exit.xpm", &img_width, &img_height);
	img->berry = mlx_xpm_file_to_image
		(vars->mlx, "xpm/berry.xpm", &img_width, &img_height);
	return (img);
}

void	ft_set_item(char **map_tab, t_img *img, t_vars *vars, t_pos pos)
{
	if (map_tab[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			img->berry, pos.x * 24, pos.y * 24);
	else if (map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			img->exit, pos.x * 24, pos.y * 24);
//	else if (map_tab[pos.y][pos.x] == 'P')
//		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
//			game->char_right, pos.x * 24, pos.y * 24);
}

void	ft_set_img(char **map_tab, t_img *img, t_vars *vars)
{
	t_pos	pos;

	pos.y = 0;
	while (map_tab[pos.y])
	{
		pos.x = 0;
		while (map_tab[pos.y][pos.x])
		{
			if (map_tab[pos.y][pos.x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					img->tree, pos.x * 24, pos.y * 24);
			else
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					img->ground, pos.x * 24, pos.y * 24);
				ft_set_item(map_tab, img, vars, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(char **map_tab)
{
	t_img	*img;
	t_map	map_content;
	t_vars	*vars;
	void	*mlx;
	void	*mlx_win;

	vars->mlx = mlx;
	vars->mlx_win = mlx_win;
	map_content = ft_get_map_stat(map_tab, map_content);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, (map_content.width * 24),
			(map_content.height * 24), "so_long");
	img = ft_init_img(map_tab, vars);
	ft_set_img(map_tab, img, vars);
	//ft_game(map_tab, img, vars, map_content);
	mlx_loop(vars->mlx);
}
