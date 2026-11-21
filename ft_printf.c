/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:49:02 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/21 15:35:20 by andrefe2         ###   ########.fr       */
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
/*
int	main(void)
{
	char	*s = "HELLO";
	printf("STRING TEST:\n");
	printf("The string is: %s\n", s);
	ft_printf("The string is: %s\n", s);

	char	c = 'A';
	printf("CHAR TEST:\n");
	printf("The char value is: %c\n", c);
	ft_printf("The char value is: %c\n", c);

	int	x;
	printf("POINTERS TEST:\n");
	printf("Adress of x = %p\n", &x);
	ft_printf("Adress of x = %p\n", &x);

	int	i = 10;
	printf("INTEGERS TEST:\n");
	printf("The int value is: %i\n", i);
	ft_printf("The int value is: %i\n", i);

	unsigned int	a = 200;
	printf("HEXADECIMAL TEST:\n");
	printf("The hexa(x) value is: %x\n", a);
	printf("The hexa(X) value is: %X\n", a);
	ft_printf("The hexa(x) value is: %x\n", a);
	ft_printf("The hexa(X) value is: %X\n", a);

	printf("PERCENT TEST:\n");
	printf("Printing %%\n");
	ft_printf("Printing %%\n");

	char	*str = "ANDRE";
	int	f = 3120;
	int	l;
	printf("MULTIPLE VARIABLES TEST:\n");
	printf("Adress: %p, Int value: %i, Hexadecimal: %x, String: %s\n", &l,f,f,str);
	ft_printf("Adress: %p, Int value: %i, Hexadecimal: %x, String: %s\n", &l,f,f,str);

}
*/
