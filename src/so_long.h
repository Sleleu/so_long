/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:18:01 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 22:44:59 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/get_next_line/get_next_line.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
/*
typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}		t_vars;*/

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	char	**map_tab;
	int		width;
	int		height;
	int		nb_c;
	int		coll_c;
	int		nb_p;
	int		nb_e;
}		t_map;

typedef struct s_img
{
	void	*char_back;
	void	*char_front;
	void	*char_left;
	void	*char_right;
	void	*tree;
	void	*ground;
	void	*exit;
	void	*berry;
}		t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

int		ft_error(/*char **map_tab, */t_map *map);
void	ft_get_map_stat(/*char **map_tab, */t_map *map);
char	**ft_set_map(int argc, char *argv, /*char **map_tab, */t_map *map);
void	ft_init_game(/*char **map_tab,*/ t_map *map);
int		ft_strlen_so_long(char *str);
void	ft_game(/*char **map_tab,*/ t_img *img, t_map *map);

#endif