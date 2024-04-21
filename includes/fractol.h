#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/libft/includes/ft_printf.h"
#include "../libs/libft/includes/libft.h"
#include "../libs/libft/includes/get_next_line_bonus.h"


#define WIDTH 512
#define HEIGHT 512

static int validate(char *fractol);
static void run_graphic(char *fractol);
int main(int argc, char **argv);

#endif