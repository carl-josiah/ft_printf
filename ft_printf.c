/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:49:31 by ccastro           #+#    #+#             */
/*   Updated: 2024/09/30 23:45:02 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (specifier == 'u')
		count += ft_putnbr_uns(va_arg(ap, unsigned int));
	if (specifier == 'x' || specifier == 'X')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), specifier);
	if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list ap;
	va_start(ap, format);
	
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
	
// }
