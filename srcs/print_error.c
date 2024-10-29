#include "solong.h"

void ft_print_error(char *str)
{
	ft_putstr_fd("Error\n\t", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
