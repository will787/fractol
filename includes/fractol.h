#ifndef FRACTOL_H
# define FRACTOL_H

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
    double colors;
    unsigned int (*map)(double, double, void*);
} t_f;

typedef enum
{
    black_white,
    circle_cromatic
} OPTIONS_COLORS;

#define WIDTH 512
#define HEIGHT 512

/*
    validate and compiler program
*/

int validate(char *fractol, t_f *frac);
void run_graphic(char *fractol, t_f *frac);
void compiler_julia(char *fractol, t_f *frac);
void compiler_mandelbrot(char *fractol, t_f *frac);
//int main(int argc, char **argv);

/* 
    functions move, set color, set paths 
*/

void key_move(void* param); 
void window_fractol(t_f *fractol, char *map);

/*
    render logic math utils
*/ 

double points_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_f sum_imaginary(t_f z1, t_f z2);
t_f square_complex(t_f z);

/*
    colors functions
*/

double circle_cromatic(double n, int cromatic);


#endif