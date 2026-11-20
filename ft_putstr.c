/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:18:23 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/20 10:40:01 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	result;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		result = ft_putchar(s[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
/*
int	main (void)
{
	char	*str = "HELLO";

	printf("\n%i", ft_putstr("HELLO"));
}
*/
