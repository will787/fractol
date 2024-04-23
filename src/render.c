#include "../includes/fractol.h"

void put_pixel(int x, int y, t_f *fractol)
{
    t_f z;
    t_f c;

    z.x = 0.0;
    z.y = 0.0;
    c.x = points_scale(x, -2, +2, 0, WIDTH);
    c.y = points_scale(y, +2, -2, 0, HEIGHT);
    int i = 0;
    while (i < WIDTH + HEIGHT)
    {
        double tmp = (z.x * z.x) - (z.y * z.y);

        z.y = 2 * z.x * z.y;

        z.x = tmp;

        z.x += c.x; // numero complex real
        z.y += c.y; // imaginary number complex

        if () // se estiver dentro do conjunto você plota de uma cor
        else // se não tiver você plota de branco, a regra de mandelbrot para pintar os pontos
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
            mlx_put_pixel(fractol->image, x, y, fractol);
        }
    }
    
}


double points_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return(new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}