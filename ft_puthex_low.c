/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:07:40 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 09:08:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_low(nbr / 16);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}
