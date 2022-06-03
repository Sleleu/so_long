/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:13:37 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/03 16:54:48 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	tab = malloc(sizeof(char) * size + 1);
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
	tab[size] = '\0';
	free(s1);
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	search;

	search = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != search)
		i++;
	if (s[i] == search)
		return ((char *)s + i);
	else
		return (NULL);
}
