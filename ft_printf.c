/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:49:31 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 15:02:07 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specification(va_list ap, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (specifier == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (specifier == 'u')
		return (ft_putnbr_uns(va_arg(ap, unsigned long)));
	if (specifier == 'x')
		return (ft_puthex_low(va_arg(ap, unsigned int)));
	if (specifier == 'X')
		return (ft_puthex_upp(va_arg(ap, unsigned int)));
	if (specifier == '%')
		return(ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += format_specification(ap, *(++format));
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			++count;
		}
		++format;
	}
	va_end(ap);
	return (count);
}
