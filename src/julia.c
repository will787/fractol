#include "../includes/fractol.h"

unsigned int	julia(double c_r, double c_i, void *vars)
{
	printf("%p", vars);
	printf("%f", c_r);
	printf("%f", c_i);
	return(1);
}