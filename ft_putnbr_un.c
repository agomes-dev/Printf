/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 12:19:24 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/20 12:27:28 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int		count;
	int		result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putnbr_un(n / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar((n % 10) + '0');
	if (result == -1)
		return (-1);
	return (count + 1);
}
/*
int	main(void)
{
	printf("\n%i", ft_putnbr_un(420));
}
*/
