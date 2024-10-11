/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:52 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 11:15:49 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	static	ul_to_hex(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ul_to_hex(nbr / 16);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ul_to_hex((unsigned long) ptr);
	return (count);
}
