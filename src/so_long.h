/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:18:01 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 21:00:09 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "../includes/get_next_line/get_next_line.h"
#include "../includes/ft_printf/ft_printf.h"

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
	void	*win;
}		t_vars;

typedef struct s_map
{
	int	width;
	int	height;
	int	nb_C;
	int	pos_P;
	int	pos_E;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

enum 
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_ESC = 53;
};

void	ft_init_charmander(void *mlx, void *mlx_win);

#endif