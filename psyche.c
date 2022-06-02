/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:41:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/02 17:53:59 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	int i = 0;
	int j = 0;
	while (1)
	{
		while (i < 1920)
		{
		j = 0;
		while (j < 1080)
		{
			//my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			if (j % 2 == 0 || j % 3 == 0)
			{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			}
			else
                        my_mlx_pixel_put(&img, i, j, 0x0000FF00);
			j++;
		}
		i++;
		}
		mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
		i = 0;
		j = 0;

                while (i < 1920)
                {
                j = 0;
                while (j < 1080)
                {
                        //my_mlx_pixel_put(&img, i, j, 0x00FF0000);
                        if (j % 2 == 0)
                        {
                        my_mlx_pixel_put(&img, i, j, 0x000000FF);
                        }
                        else
                        my_mlx_pixel_put(&img, i, j, 0x0000FFFF);
                        j++;
                }
                i++;
                }
                mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
                i = 0;
                j = 0;

                while (i < 1920)
                {
                j = 0;
                while (j < 1080)
                {
                        //my_mlx_pixel_put(&img, i, j, 0x00FF0000);
                        if (j % 2 == 0)
                        {
                        my_mlx_pixel_put(&img, i, j, 0x0000FF00);
                        }
                        else
                        my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
                        j++;
                }
                i++;
                }
                mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
                i = 0;
                j = 0;
	}

	mlx_loop(mlx);

	return (0);
}