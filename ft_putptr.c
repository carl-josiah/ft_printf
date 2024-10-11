/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:52 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 14:55:51 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	static	ul_to_hex(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ul_to_hex(nbr / 16);
	if (write(1, &"0123456789abcdef"[nbr % 16], 1) == -1)
		return (-1);
	++count;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	count += ul_to_hex((unsigned long) ptr);
	if (count == -1)
		return (-1);
	return (count + 2);
}
