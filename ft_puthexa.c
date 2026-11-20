/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:24:31 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/20 14:59:44 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char percent)
{
	int		count;
	int		result;
	char	*hexa;

	count = 0;
	if (n >= 16)
	{
		result = ft_puthexa(n / 16, percent);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (percent == 'x')
		hexa = "0123456789abcdef";
	if (percent == 'X')
		hexa = "0123456789ABCDEF";
	result = ft_putchar(hexa[n % 16]);
	if (result == -1)
		return (-1);
	return (count + 1);
}
/*
int	main(void)
{
	printf("\n%i\n", ft_puthexa(1200, 'X'));
	printf("\n%i", ft_puthexa(1200, 'x'));
}
*/
