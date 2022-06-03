/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:52:50 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 18:29:49 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	ft_init_charmander(void *mlx, void *mlx_win)
{
	void	*charmander_back;
	void	*charmander_front;
	void	*charmander_left;
	void	*charmander_right;
	int	img_width;
	int	img_height;

	charmander_back = mlx_xpm_file_to_image(mlx, "xpm/charmander_back.xpm", &img_width, &img_height);
	charmander_front = mlx_xpm_file_to_image(mlx, "xpm/charmander_front.xpm", &img_width, &img_height);
	charmander_left = mlx_xpm_file_to_image(mlx, "xpm/charmander_left.xpm", &img_width, &img_height);
	charmander_right = mlx_xpm_file_to_image(mlx, "xpm/charmander_right.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, charmander_back, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, charmander_front, 32, 32);
	mlx_put_image_to_window(mlx, mlx_win, charmander_left, 128, 0);
	mlx_put_image_to_window(mlx, mlx_win, charmander_right, 192, 0);
	mlx_loop(mlx);
}