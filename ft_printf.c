/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:49:02 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/19 17:34:54 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent_type(const char *format, args)
{
	if (== 'c')
		ft_putchar();
	if (== 's')
		ft_putstr();
	if (== 'p')
		ft_putpointer();
	if (== 'd' || == 'i' || == 'u')
		ft_putnbr();
	if (== 'x' || == 'X')
		ft_puthexa();
	if (== '%')
		ft_putchar('%');

}


int	ft_printf(const char *format, ...)
{

}
