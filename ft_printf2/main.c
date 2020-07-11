
#include "ft_printf.h"
#include <stdio.h>

int main()
{
//	printf("TEST#1:\n\n");
//	printf("Hello, World!\n");
//	ft_printf("Hello, World!\n");
//	printf("\n--------------------------\n");
//
//	printf("TEST#2:\n\n");
//	printf("|%-*c|\n", 10, 'a');
//	ft_printf("|%-*c|\n", 10, 'a');
//	printf("\n--------------------------\n");

	printf("|%*s|\n", 1, "Hello");
	ft_printf("|%*s|\n", 1, "Hello");
//	ft_printf("|%0*.10d|\n", 15, -213);

	return 0;
}
