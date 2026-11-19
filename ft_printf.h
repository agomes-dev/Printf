/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:49:05 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/19 17:33:44 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	FT_PRINTF_H
# define	FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif
