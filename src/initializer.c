#include "../includes/fractol.h"

int validate(char *fractol, t_f *frac)
{
    if(ft_strncmp(fractol, "julia", ft_strlen("mandelbrot")) == 0)
    {
        run_graphic(fractol, frac);
        return(ft_putstr_fd("Map selected, correctly\n", 1));
    }
    else if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")) == 0)
    {
        run_graphic(fractol, frac);
        return(ft_putstr_fd("Map selected, correctly\n", 1));
    }
    else
    {
        ft_putstr_fd("Map invalid, please try again\n", 1);
        return(EXIT_FAILURE);
    }
    return 1;
}

void run_graphic(char *fractol, t_f *frac)
{
    if(ft_strncmp(fractol, "julia", ft_strlen("julia")))
        compiler_julia(fractol, frac);
    else if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")))
        compiler_mandelbrot(fractol, frac);
}

void compiler_julia(char *fractol, t_f *frac)
{
    frac->map = black_white;
    ft_printf("oi %s\n", fractol);
}

void compiler_mandelbrot(char *fractol, t_f *frac)
{
    frac->map = black_white;
    printf("oi %s\n", fractol);
}