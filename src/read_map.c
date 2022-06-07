/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:32:00 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 22:44:14 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
//#include <mlx.h>

#include <stdlib.h> //SUPP
#include <fcntl.h> //SUPP
#include <stddef.h> //SUPP

int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*ft_strjoin_so_long(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen_so_long(s1) + ft_strlen_so_long(s2));
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[size] = '/';
	tab[size + 1] = '\0';
	return (tab);
}

char	**ft_read_map(int fd)
{
	char	*line;
	char	*map_line;
	char	**map_tab;

	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = ft_strjoin_so_long(map_line, line);
		free(line);
	}
	map_tab = ft_split(map_line, '/');
	return (map_tab);
}

void	ft_get_map_stat(/*char **map_tab, */t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->height = 0;
	map->width = ft_strlen_so_long(map->map_tab[y]);
	map->nb_c = 0;
	map->nb_p = 0;
	map->nb_e = 0;
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][++x])
		{
			if (map->map_tab[y][x] == 'C')
				map->nb_c++;
			else if (map->map_tab[y][x] == 'P')
				map->nb_p++;
			else if (map->map_tab[y][x] == 'E')
				map->nb_e++;
		}
		map->height++;
		y++;
	}
	//return (map);
}

char	**ft_set_map(int argc, char *argv, /*char **map_tab, */t_map *map)
{
	//t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error \nInvalid argument\n");
		return (NULL);
	}
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nFailed to open file\n");
		return (NULL);
	}
	map->map_tab = ft_read_map(fd);
	close(fd);
	ft_get_map_stat(/*map_tab, */map);
	if (ft_error(/*map_tab, */map) == 0)
		return (NULL);
	return (map->map_tab);
}
/*
int	main(int argc, char **argv)
{
	char	**map_tab;
	map_tab = ft_set_map(argc, argv[1], map_tab);
		if (!map_tab)
			return (1);

	int	i = -1;

	while (map_tab[++i])
		printf("%s\n", map_tab[i]);
	return (0);
}*/