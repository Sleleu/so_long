/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:18:01 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 18:50:01 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

#include "../includes/get_next_line/get_next_line.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/libft/libft.h"

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}		t_vars;

typedef struct s_map
{
	int	width;
	int	height;
	int	nb_C;
	int	nb_P;
	int	nb_E;
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

void	ft_init_charmander(void *mlx, void *mlx_win);
int	ft_error(char **map_tab, t_map map_content);
t_map	ft_get_map_stat(char **map_tab, t_map map_content);
char	**ft_set_map(int argc, char *argv, char **map_tab);
void	ft_init_game(char **map_tab);
int	ft_strlen_so_long(char *str);
void	ft_game(char **map_tab, t_img *img, t_vars *vars, t_map map_content);

#endif