/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:07:40 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/09 11:53:31 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long nbr, char specifier)
{
	int		i;
	int		count;
	char	str[9];
	char	*nbr_case;

	i = 0;
	count = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (specifier == 'X')
	{
		nbr_case = "0123456789ABCDEF";
		while (nbr)
		{
			// str[i] = nbr_case [nbr % 16];
			// nbr = nbr / 16;
			// i++;
			count += ft_putnbr_hex(nbr / 16, 'X');
			count += ft_putnbr_hex(nbr % 16, 'X');
		}
	}
	else if (specifier == 'x')
	{
		nbr_case = "0123456789abcdef";
		while (nbr)
		{
			// str[i] = nbr_case [nbr % 16];
			// nbr = nbr / 16;
			// i++;
			count += ft_putnbr_hex(nbr / 16, 'x');
			count += ft_putnbr_hex(nbr % 16, 'x');
		}
	}
	while (i)
	{
		count += ft_putchar(str[i]);
		i--;
	}
	// else
		// count += ft_putchar(nbr + '0');
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_putnbr_hex(123, 'x');
	printf("\ncount %d\n", count);
}

