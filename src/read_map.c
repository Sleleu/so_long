/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:32:00 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/06 21:39:53 by sleleu           ###   ########.fr       */
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

//	if (fd <= 0)
//		ft_printf("Error\n Failed to open file\n");
//			return (NULL);
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

t_map	ft_get_map_stat(char **map_tab, t_map map_content)
{
	int	y;
	int	x;

	y = 0;
	map_content.width = ft_strlen_so_long(map_tab[y]);
	map_content.height = 0;
	map_content.nb_C = 0;
	map_content.nb_P = 0;
	map_content.nb_E = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][++x])
		{
			if (map_tab[y][x] == 'C')
				map_content.nb_C++;
			else if (map_tab[y][x] == 'P')
				map_content.nb_P++;
			else if (map_tab[y][x] == 'E')
				map_content.nb_E++;
		}
		map_content.height++;
		y++;
	}
	return (map_content);
}

int	ft_set_map(char *argv)
{
	t_map	map_content;
	char	**map_tab;
	int		fd;
	fd = open(argv, O_RDONLY);
	map_tab = ft_read_map(fd);
	close(fd);
	map_content = ft_get_map_stat(map_tab, map_content);
	if (ft_error(map_tab, map_content) == 0);
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_set_map(argv[1]);
	return (0);
}