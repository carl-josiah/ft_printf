#include "ft_printf.h"

int	main(void)
{
	int nbr;
	int	count;

	nbr = 1234567890;
	count = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	printf("%d\n", count);
}