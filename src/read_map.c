/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:32:00 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/06 17:14:40 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
//#include <mlx.h>

#include <stdlib.h> //SUPP
#include <fcntl.h> //SUPP
#include <stddef.h> ///SUPP

static int	ft_strlen_so_long(char *str)
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
	//free(s1);
	return (tab);
}
/*
void	ft_check_map(char *line, t_map *map, int y)
{
	int	x;

	x = 0;
	map->nb_C = 0; // pas de C dans la premiere ligne
	while (line[x])
	{
		if (line[x] == 'C')
			map.nb_C++;
		else if (line[x] == 'P')
			map.pos_P = x * y; // le P ne peut pas etre a un emplacement 0
		else if (line[x] == 'E')
			map.pos_E == x * y;
		x++;
	}
}*/

void	ft_read_map(int fd, char **map_tab)
{
	char	*line;
	char	*map_line;

	//line = get_next_line(fd);
	//map_line = ft_strjoin_so
	//free(line);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = ft_strjoin_so_long(map_line, line);
		free(line);
	}
	printf("%s", map_line);
	map_tab = ft_split(map_line, '/');
		int	i = 0;
	printf("\n");
	while (i<5)
	{
		printf("%s\n", map_tab[i]);
		i++;
	}
}

void	ft_set_map(char *argv)
{
	int	fd;
	char	**map_tab;
	
	fd = open(argv, O_RDONLY);
	ft_read_map(fd, map_tab);
	close(fd);
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_set_map(argv[1]);
	return (0);
}