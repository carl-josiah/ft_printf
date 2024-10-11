#include "ft_printf.h"

int	main(void)
{
	int	count = ft_printf("%%c");
	printf("\nthe count: %d\n", count);
	printf("%%%c\n", 'x');
	ft_printf("%%%c\n", 'x');
}