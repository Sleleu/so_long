/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:41:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/09 01:50:33 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		return (1);
	}
	if (!ft_test_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nFailed to open file\n");
		return (0);
	}
	if (!ft_set_map(fd, &map))
	{
		free_map_tab(&map);
		return (1);
	}
	ft_init_game(&map);
	return (0);
}
