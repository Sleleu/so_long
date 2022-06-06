/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:18:01 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/06 21:10:06 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "../includes/get_next_line/get_next_line.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/libft/libft.h"

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
	int	nb_P;
	int	nb_E;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

void	ft_init_charmander(void *mlx, void *mlx_win);
int	ft_error(char **map_tab, t_map map_content);
int	ft_strlen_so_long(char *str);

#endif