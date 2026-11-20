/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:29:37 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/20 15:08:33 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void	*p)
{
	int				result;
	int				count;
	unsigned long	adress;

	count = 0;
	adress = (unsigned long)p;
	if (p == NULL)
		return (ft_putstr("(nil)"));
	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	count += result;
	result = ft_puthexa(adress, 'x');
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
/*
int	main(void)
{
	int	x;

	printf("\n%i", ft_putpointer(&x));
}
*/
