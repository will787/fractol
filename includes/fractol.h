#ifndef FRACTOL_H
# define FRACTOL_H
# define ITERS 200

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/libft/includes/ft_printf.h"
#include "../libs/libft/includes/libft.h"
#include "../libs/libft/includes/get_next_line_bonus.h"

typedef struct
{
    mlx_t *mlx;
    mlx_image_t *image;
    double iters;
    double colors_pixel;
    int color_proto;
    int x;
    int y;
    int32_t			x_mouse;
	int32_t			y_mouse;
	double			x_spam;
	double			y_spam;
	double			x_offset;
	double			y_offset;
	double			x_seed;
	double			y_seed;
	double			zoom;
    unsigned int (*map)(double, double, void*);
} t_f;

typedef enum
{
    black_white,
    circle_colors
} OPTIONS_COLORS;

typedef enum 
{
    MLX_FAILURE,
    MLX_IMAGE_FAIL,
    TO_MANY_ARGS,
    MAP_INVALID
} errors;

#define WIDTH 512
#define HEIGHT 512

/**************************
    validate and compiler program
*/
void validate(char *fractol, t_f *frac);
void run_graphic(char *fractol, t_f *frac);
void compiler_julia(char *fractol, t_f *frac);
void compiler_mandelbrot(char *fractol, t_f *frac);
//int main(int argc, char **argv);

/**************************
    render logic math utils
*/ 
unsigned int mandelbrot(double c_r, double c_i, void *vars);

/* *************************
    functions move, set color, set paths 
*/
void    key_move(void* param); 
void    window_fractol(t_f *fractol, char *map);

/**************************
    render logic math utils
*/ 
//double          points_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
//t_f             sum_imaginary(t_f z1, t_f z2);
//t_f             square_complex(t_f z);
void            render(t_f *fractol);
double   ft_x_value(const t_f *f, int x_coord);
double   ft_y_value(const t_f *f, int y_coord);

/*************************
    colors functions
*/
double	color_factor(t_f *frac);
uint32_t	color_rgba(int r, int g, int b, int a);
double circle_cromatic(double n, int cromatic);
double black__white(double n);


/*************************
    functions errors
*/
void ft_errors(void *p, int type_er);
void close_program(void *p, int type_er);
#endif