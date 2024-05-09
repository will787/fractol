#include "../includes/fractol.h"

unsigned int	julia(double c_r, double c_i, void *vars)
{
	unsigned int n;
	double z_i;
	double z_r;
	double tmp;
	t_f *frac;

	frac = vars;
	n = -1;
	while (++n < frac->iters)
	{
		if((c_i * c_i + c_r * c_r) > 4)  //c_i² + c_r²
			break;
		
		tmp = 2 * c_r * c_i + frac->y_seed;
		c_r = elevate_n(c_r) - elevate_n(c_i) + frac->x_seed;
		c_i = tmp;
	}
	return (n);	
}

double elevate_n(double n)
{
	return n * n;
}