/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:49:31 by ccastro           #+#    #+#             */
/*   Updated: 2024/09/28 11:06:28 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	print_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == INT_MIN)
	{
		count += print_char('-');
		count += print_char('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		print_char('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		print_nbr(nbr / 10);
		print_nbr(nbr % 10);
	}
	else
		count += print_char(nbr + '0');
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int	count;
	
	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	if (specifier == 'p')
		count += print_ptr(va_arg(ap, void *));
	if (specifier == 'd' || specifier == 'i')
		count += print_nbr(va_arg(ap, int));
	if (specifier == 'u')
		count += print_unsi(va_arg(ap, unsigned int));
	if (specifier == 'x' || specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), specifier);
	if (specifier == '%')
		count += print_char('%');
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

int	main(void)
{
	
}