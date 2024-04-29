#include "../includes/fractol.h"

uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double black__white(double n)
{
    n = 1 - n;
    n *= 255;
    return(color_rgba(n, n, n, 255));
}


double circle_cromatic(double n, int cromatic)
{
    if(cromatic == black__white)
        return (black__white(n));
    return -1;
}