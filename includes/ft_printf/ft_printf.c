/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:12:10 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/16 18:04:18 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	if (format[len] == '%' && format[len + 1] == '\0')
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_format(format++, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			len++;
		}
		if (*format == '\0')
			break ;
	}
	va_end(args);
	return (len);
}
