#include "../includes/fractol.h"

void put_pixel(int x, int y, t_f *fractol)
{
    t_f z;
    t_f c;
    int i;

    z.x = 0.0;
    z.y = 0.0;
    c.x = points_scale(x, -2, +2, 0, WIDTH);
    c.y = points_scale(y, +2, -2, 0, HEIGHT);
    i = -1;
    while (++i < fractol->iters)
    {
        z = sum_imaginary(square_complex(z), c);
        if((z.x * z.x ) + (z.y * z.y) > 4.0)
        {
            fractol->colors = black__white(i);
            double tmp_color = fractol->colors;
            mlx_put_pixel(fractol->image, x, y, tmp_color);
        }
    }   
}

void render(t_f *fractol)
{
    int x;
    int y;
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            put_pixel(x,y, fractol);
        }
    }
}

double points_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return(new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_f sum_imaginary(t_f z1, t_f z2)
{
    t_f plus_i;

    plus_i.x = z1.x + z2.x;
    plus_i.y = z1.y + z2.y;
    return plus_i;
}

t_f square_complex(t_f z)
{
    t_f tmp;

    tmp.x = (z.x * z.x) -(z.y * z.y);
    tmp.y = 2 * z.x * z.y;
    return tmp;
}