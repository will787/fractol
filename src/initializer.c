#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    if(argc != 2)
        return 0;
    validate(argv[1]);    
    return(0);
}

static int validate(char *fractol)
{
    if(ft_strncmp(fractol, "julia", ft_strlen("mandelbrot")) == 0)
    {
        run_graphic(fractol);
        return(ft_putstr_fd("Map selected, correctly\n", 1));
    }
    else if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")) == 0)
    {
        run_graphic(fractol);
        return(ft_putstr_fd("Map selected, correctly\n", 1));
    }
    else
        return(EXIT_FAILURE);
}

static void run_graphic(char *fractol)
{
    printf("oi %s\n\n", fractol);
}