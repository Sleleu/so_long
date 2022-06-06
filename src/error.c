/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:32:28 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/06 23:10:14 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	ft_entity_error(t_map map_content)
{
	if (map_content.nb_P != 1)
	{
		ft_printf("Error\n Map must have one starting position\n");
		return (0);
	}
	else if (map_content.nb_E == 0)
	{
		ft_printf("Error\n Map must have one exit or more\n");
		return (0);
	}
	else if (map_content.nb_C == 0)
	{
		ft_printf("Error \n Map must have one collectible or more\n");
		return (0);
	}
	return (1);
}

int	ft_form_error(char **map_tab, t_map map_content)
{
	int	i;
	int	j;
	int	total_size;

	i = 0;
	j = 0;
	total_size = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			total_size++;
			j++;
		}
		i++;
	}
	if ((map_content.height * map_content.width) != total_size)
	{
		ft_printf("Error \n Map must be rectangular\n");
		return (0);
	}
	return (1);
}

int	ft_wall_error(char **map_tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen_so_long(map_tab[i]) - 1;
	while (map_tab[i][j])
	{
		if (map_tab[i][j++] != '1')
			return (0);
	}
	i++;
	while (map_tab[i])
	{
		if (map_tab[i][0] != '1' || map_tab[i][len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map_tab[i - 1][j])
	{
		if (map_tab[i - 1][j++] != '1')
			return (0);
	}
	return (1);
}

int	ft_error(char **map_tab, t_map map_content)
{
	if (!ft_form_error(map_tab, map_content) || !ft_entity_error(map_content))
		return (0);
	else if (!ft_wall_error(map_tab))
	{
		ft_printf("Error\n Map not closed\n");
		return (0);
	}
	return (1);
}