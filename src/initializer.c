#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    t_f *frac;
    frac = (t_f *)malloc(sizeof(t_f));
    if(argc != 2)
        return 0;
    validate(argv[1],frac);  
    window_fractol(frac, argv[1]);
    return(0);
}

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
    frac->map = fractol;
    ft_printf("oi %s\n", fractol);
}

void compiler_mandelbrot(char *fractol, t_f *frac)
{
    printf("oi %s\n", fractol);
}