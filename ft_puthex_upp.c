/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:38:19 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 14:15:19 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upp(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_upp(nbr / 16);
	if (write(1, &"0123456789ABCDEF"[nbr % 16], 1) == -1)
		return (-1);
	++count;
	return (count);
}
