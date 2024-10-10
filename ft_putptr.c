/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:52 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/10 17:02:31 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	hex_low(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		hex_low(nbr / 16);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}

int	ft_putptr(unsigned long nbr)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	hex_low(nbr);
	return (count);
}
