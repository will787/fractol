#include "../includes/fractol.h"

void ft_errors(void *p, int type_er)
{
    if(type_er == MAP_INVALID)
        ft_putstr_fd("Map invalid, please select correctly map\n", 1);
    else if(type_er == TO_MANY_ARGS)
        ft_putstr_fd("Arguments for necessary the compiler: ./fractol {map}\n", 1);
    else if(type_er == MLX_FAILURE)
        ft_putstr_fd("Creation failure mlx window\n", 1);
    else if(type_er == MLX_IMAGE_FAIL)
        ft_putstr_fd("Failure view image, try again\n", 1);
    close_program(p, type_er);
}

void close_program(void *p, int type_er)
{
    t_f *param;

    param = (t_f *)p;

    if(param->image)
        mlx_delete_image(param->mlx, param->image);
    if(param->mlx)
    {
        mlx_close_window(param->mlx);
        mlx_terminate(param->mlx);
    }
    exit(type_er);
}