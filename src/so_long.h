/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:18:01 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/08 23:45:22 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/get_next_line/get_next_line.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	void	*char_back;
	void	*char_front;
	void	*char_left;
	void	*char_right;
	void	*tree;
	void	*ground;
	void	*exit;
	void	*berry;
	void	*berry2;
	char	**map_tab;
	int		width;
	int		height;
	int		nb_c;
	int		get_c;
	int		nb_p;
	int		p_x;
	int		p_y;
	int		nb_e;
	int		nb_move;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

/* read_map */

char	**ft_set_map(int argc, char *argv, t_map *map);
void	ft_get_map_stat(t_map *map);
void	ft_read_map(int fd, t_map *map);
char	*ft_strjoin_so_long(char *s1, char *s2);
int		ft_strlen_so_long(char *str);

/* error */

int		ft_error(t_map *map);
int		ft_wall_error(t_map *map, int len);
int		ft_form_error(t_map *map, int len);
int		ft_entity_error(t_map *map);
int		ft_char_error(t_map *map);

/* init_game */

void	ft_set_img(t_map *map);
void	ft_set_item(t_map *map, t_pos pos);
void	ft_init_game(t_map *map);
void	ft_init_img(t_map *map);

/* game */

void	ft_game(t_map *map);
int		close_game(t_map *map);
void	destroy_image(t_map *map);
void	free_map_tab(t_map *map);

/* move */

int		key_hook(int keycode, t_map *map);
void	move_a(int keycode, t_map *map);
void	move_s(int keycode, t_map *map);
void	move_d(int keycode, t_map *map);
void	move_w(int keycode, t_map *map);

/* set_textures */

void	set_char(int keycode, t_map *map);
void	set_ground(t_map *map, int y, int x);
int		check_exit(t_map *map, int y, int x);
void	check_item(t_map *map, int y, int x);

#endif