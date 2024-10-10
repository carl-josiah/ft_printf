/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:52 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/08 13:17:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// int	ft_putptr(void *ptr)
// {
	
// }

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

// int ft_putchar(char c) {
//     return write(1, &c, 1);
// }

// int ft_putnbr_base(unsigned long nbr, const char *base) {
//     int count = 0;
//     if (nbr >= 16) {
//         count += ft_putnbr_base(nbr / 16, base);
//     }
//     count += ft_putchar(base[nbr % 16]);
//     return count;
// }

int ft_putptr(void *ptr) {
    unsigned long address = (unsigned long) ptr;
    int count = 0;

    // Print the "0x" prefix
    count += ft_putchar('0');
    count += ft_putchar('x');

    // Print the hexadecimal representation of the pointer
    count += ft_putnbr_hex(address, 'x');

    return count;
}

// Usage example
int main() {
    int x = 4;
	void *ptr = &x;
	// unsigned long address = (unsigned long) ptr;
	printf("%lu\n", (unsigned long) ptr);
    ft_putptr(&x);  // Example usage
	printf("\n%p\n", &x);
    return 0;
}
