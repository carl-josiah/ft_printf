/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:49:31 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/10 17:00:28 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (specifier == 'p')
		count += ft_putptr(va_arg(ap, unsigned long));
	if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (specifier == 'u')
		count += ft_putnbr_uns(va_arg(ap, unsigned long));
	if (specifier == 'x')
		count += ft_puthex_low(va_arg(ap, unsigned int));
	if (specifier == 'X')
		count += ft_puthex_upp(va_arg(ap, unsigned int));
	if (specifier == '%')
		write(1, "&", 1);
	return (count);
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
			count += print_format(*(++format), ap);
		else
			write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("Hello %s! I am %d years old :(\n", "Carl", 50);
// }
