/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:32:00 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 21:43:46 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	ft_error(char *argc)
{
	
}

void	ft_check_map(char *line, t_map *map, int y)
{
	int	x;
	
	x = 0;
	while (line[x])
	{
		if (line[x] == 'C')
			map.nb_C++;
		else if (line[x] == 'P')
			map.pos_P = x * y; // le P ne peut pas etre a un emplacement 0 si pas error
		else if (line[x] == 'E')
			map.pos_E == x * y;
		x++;
	}
}

t_map	*ft_read_map(char *argv)
{
	char	*line;
	int	fd;
	int	width;
	int	y;
	t_map	*map;
	
	y = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	map->height = 0;
	map->nb_C = 0; // pas de C dans la premiere ligne
	free(line);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		y++;
		ft_check_map(line, map, y);
		free(line);
	}
	close(fd);
	return (map);
}

void	ft_set_map(char *argv)
{
	int	x;
	int	y;
	t_map	*map;
	
	map = ft_read_map(char *argv);
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
	}
}