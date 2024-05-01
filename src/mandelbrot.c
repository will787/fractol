#include "../includes/fractol.h"

unsigned int mandelbrot(double c_r, double c_i, void *vars)
{
    unsigned int n;
    double z_r;
    double z_i;
    double tmp;
    t_f *fractol;

    fractol = (t_f *)vars;
    z_r = 0.0;
    z_i = 0.0;
    n = -1;
    while (++n < fractol->iters) {
        if ((z_r * z_r + z_i * z_i) > 4.0)
            break ;
        tmp = 2 * z_r * z_i + c_i;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = tmp;
    }
    return n;
}

// t_f sum_imaginary(t_f z1, t_f z2)
// {
//     t_f plus_i;

//     plus_i.x = z1.x + z2.x;
//     plus_i.y = z1.y + z2.y;
//     return plus_i;
// }

// t_f square_complex(t_f z)
// {
//     t_f tmp;

//     tmp.x = (z.x * z.x) -(z.y * z.y);
//     tmp.y = 2 * z.x * z.y;
//     return tmp;
// }

// double points_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
// {
//     return(new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
// }