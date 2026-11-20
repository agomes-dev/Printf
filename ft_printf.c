/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:49:02 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/20 15:09:12 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent_type(const char type, va_list *args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (type == 'p')
		return (ft_putpointer(va_arg(*args, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (type == 'u')
		return (ft_putnbr_un(va_arg(*args, unsigned int)));
	if (type == 'x' || type == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), type));
	if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			result = ft_percent_type(format[i + 1], &args);
			i++;
		}
		else
			result = ft_putchar(format[i]);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
