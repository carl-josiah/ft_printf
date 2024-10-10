/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:38:19 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/10 16:57:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upp(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_upp(nbr / 16);
	count += ft_putchar("0123456789ABCDEF"[nbr % 16]);
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_puthex_upp(255);
	printf("\nthe count is %d\n", count);
}
