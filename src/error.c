/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:32:28 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/07 14:12:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	ft_entity_error(t_map map_content)
{
	if (map_content.nb_P != 1)
	{
		ft_printf("Error\nMap must have one starting position\n");
		return (0);
	}
	else if (map_content.nb_E == 0)
	{
		ft_printf("Error\nMap must have one exit or more\n");
		return (0);
	}
	else if (map_content.nb_C == 0)
	{
		ft_printf("Error \nMap must have one collectible or more\n");
		return (0);
	}
	return (1);
}

int	ft_form_error(char **map_tab, t_map map_content, int len)
{
	int	i;

	i = 0;
	while (map_tab[i])
	{
		if (len != ft_strlen_so_long(map_tab[i]) - 1)
		{
			ft_printf("Error \nMap must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_wall_error(char **map_tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	int	len;

	len = ft_strlen_so_long(map_tab[0]) - 1;
	if (!ft_form_error(map_tab, map_content, len)
		|| !ft_entity_error(map_content))
		return (0);
	else if (!ft_wall_error(map_tab, len))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	return (1);
}
