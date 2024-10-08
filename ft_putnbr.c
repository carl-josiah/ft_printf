/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 23:33:11 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/10 16:58:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putnbr(int nbr)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr == INT_MIN)
// 		return (ft_putstr("-2147483648"));
// 	if (nbr < 0)
// 	{
// 		count += ft_putchar('-');
// 		nbr = -nbr;
// 	}
// 	if (nbr > 9)
// 	{
// 		count += ft_putnbr(nbr / 10);
// 		count += ft_putnbr(nbr % 10);
// 	}
// 	else
// 		count += ft_putchar(nbr + '0');
// 	return (count);
// }

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

// int	main(void)
// {
// 	int	count;

// 	count = ft_putnbr(100);
// 	printf("\ncount %d\n", count);
// }