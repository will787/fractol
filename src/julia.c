#include "../includes/fractol.h"

unsigned int	julia(double c_r, double c_i, void *vars)
{
	unsigned int n;
	double tmp;
	t_f *frac;

	frac = vars;
	n = -1;
	while (++n < frac->iters)
	{
		if(pow((c_i * c_i + c_r * c_r), 2) > 2)  //c_i² + c_r²
			break;
		tmp = 2 * c_r * c_i + frac->y_seed;
		c_r =  pow(c_r, 2) - pow(c_i, 2) + frac->x_seed;
		c_i = tmp;
	}
	return (n);	
}