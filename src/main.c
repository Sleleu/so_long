/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:41:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/08 20:03:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_map	map;
	int		test_fd;
	char	*test_file;

	test_fd = open(argv[1], O_RDONLY);
	if (!read(test_fd, test_file, 1))
	{
		ft_printf("Error\nEmpty file\n");
		return (1);
	}
	close(test_fd);
	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		return (1);
	}
	if (!ft_set_map(argc, argv[1], &map))
		return (1);
	ft_init_game(&map);
	return (0);
}
