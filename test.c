#include "ft_printf.h"

// void	function(int a)
// {
// 	if (a <= 0)
// 		printf("%d\n", a);
// 	else
// 	{
// 		printf("%d\n", a);
// 		function(a - 1);
// 	}
// }

// void decimal(int nbr)
// {
// 	if (nbr < 9)
	
// }

// int	main(void)
// {
// 	function(10);
// }



void placenbr(int nbr)
{
	char n;
	if (nbr >= 10)
		placenbr(nbr / 10);
	n = (nbr % 10) + '0';
	write(1, &n, 1);
}

int	main(void)
{
	placenbr(100);
}