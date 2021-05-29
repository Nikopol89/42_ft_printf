#include "ft_printf.h"
#include <limits.h> /* TEST */
#include <stdio.h>

int		main (void)
{
	char array[9] = "magic dog";
	char *empty = 0;
	int n = INT_MIN;
	int n2 = 8;

	printf(" RET=%d\n", 
		ft_printf(
			"%.p", NULL));
	printf(" RET=%d\n", 
		printf(
			"%.p", NULL));
	(void)array;
	(void)empty;
	(void)n;
	(void)n2;
	return (0);
}
