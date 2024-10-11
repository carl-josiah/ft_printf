/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 23:33:11 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/11 16:12:00 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;
	int	out;
	int	tmp;

	count = 0;
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		tmp = ft_putchar('-');
		if (tmp == -1)
			return (-1);
		count += tmp;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		if (count == -1)
			return (-1);
	}
	out = (nbr % 10) + '0';
	if (write(1, &out, 1) == -1)
		return (-1);
	++count;
	return (count);
}
