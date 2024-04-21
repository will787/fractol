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
    int x;
    int y;
    mlx_t *mlx;
    mlx_image_t *image;
} t_f;


#define WIDTH 512
#define HEIGHT 512

int validate(char *fractol);
void run_graphic(char *fractol);
void compiler_julia(char *fractol);
void compiler_mandelbrot(char *fractol);
int main(int argc, char **argv);

/* functions move, set color, set paths */

void key_move(void* param); 
void window_fractol(t_f *fractol, char *map);

#endif