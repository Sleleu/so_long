/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:32:28 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 22:52:56 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	ft_entity_error(t_map *map)
{
	if (map->nb_p != 1)
	{
		ft_printf("Error\nMap must have one starting position\n");
		return (0);
	}
	else if (map->nb_e == 0)
	{
		ft_printf("Error\nMap must have one exit or more\n");
		return (0);
	}
	else if (map->nb_c == 0)
	{
		ft_printf("Error \nMap must have one collectible or more\n");
		return (0);
	}
	return (1);
}

int	ft_form_error(t_map *map, int len)
{
	int	i;

	i = 0;
	while (map->map_tab[i])
	{
		if (len != ft_strlen_so_long(map->map_tab[i]) - 1)
		{
			ft_printf("Error \nMap must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_wall_error(t_map *map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tab[i][j])
	{
		if (map->map_tab[i][j++] != '1')
			return (0);
	}
	i++;
	while (map->map_tab[i])
	{
		if (map->map_tab[i][0] != '1' || map->map_tab[i][len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map->map_tab[i - 1][j])
	{
		if (map->map_tab[i - 1][j++] != '1')
			return (0);
	}
	return (1);
}

int	ft_error(t_map *map)
{
	int	len;

	len = ft_strlen_so_long(map->map_tab[0]) - 1;
	if (!ft_form_error(map, len)
		|| !ft_entity_error(map))
		return (0);
	else if (!ft_wall_error(map, len))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	return (1);
}
