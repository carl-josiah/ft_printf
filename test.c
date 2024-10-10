#include <stdio.h>
#include <unistd.h>


int	main(void)
{
	write(1, &"0123456789abdef"[15 % 16], 1);
	printf("%d\n", 15 % 16);
}