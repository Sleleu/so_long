/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:52:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/24 16:07:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	tab = malloc(sizeof(char) * size + 1);
	tab[size] = '\0';
	if (tab == NULL)
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	return (tab);
}
/*
   int main(void)
   {
	char	tab[2];
   printf("%s\n", ft_strjoin(tab, "1"));
	ft_strjoin(tab, "2");
	ft_strjoin(tab, "\0");
	printf("%s\n", tab);
   }*/
