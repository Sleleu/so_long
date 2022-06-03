/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:41:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 18:31:07 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

// PUT PIXELS ON WINDOW
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 300, "so_long");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	//&img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	ft_init_charmander(mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}