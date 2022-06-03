/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:25:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 20:00:48 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line/get_next_line.h"
#include "../includes/ft_printf/ft_printf.h"

char	*ft_reverse_str(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*reverse;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	reverse = malloc(sizeof(char) * len + 1);
	while (str[i])
		i++;
	i--;
	while (str[i])
	{
		reverse[j] = str[i];
		i--;
		j++;
	}
	free(str);
	return (reverse);
}

// TO COMPILE :
// gcc -Wall -Werror -Wextra ft_reverse_xpm.c 
// ../includes/get_next_line/*.c ../includes/ft_printf/*.c
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("charmander_left.xpm", O_RDONLY);
	if (fd >= 0)
	{
		while (1)
		{
			str = get_next_line(fd);
			if (!str)
				break ;
		str = ft_reverse_str(str);
		ft_printf("%s", str);
				free(str);
		}
		close(fd);
	}
	return (0);
}*/