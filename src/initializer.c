#include "../includes/fractol.h"

void validate(char *fractol, t_f *frac)
{
    if(ft_strncmp(fractol, "julia", ft_strlen("mandelbrot")) == 0)
        run_graphic(fractol, frac);
    else if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")) == 0)
        run_graphic(fractol, frac);
    else
        ft_errors(frac, MAP_INVALID);
}

void run_graphic(char *fractol, t_f *frac)
{
    if(ft_strncmp(fractol, "julia", ft_strlen("julia")))
        compiler_julia(fractol, frac);
    else if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")))
        compiler_mandelbrot(fractol, frac);
}

void compiler_mandelbrot(char *fractol, t_f *frac)
{
    frac->map = mandelbrot;
    frac->x_spam = 3;
	frac->y_spam = 3;
	frac->x_offset = 2.3;
	frac->y_offset = 1.5;
    render(frac);
    ft_printf("oi %s\n", fractol);
}

void compiler_julia(char *fractol, t_f *frac)
{
    render(frac);
    ft_printf("oi %s\n", fractol);
}
