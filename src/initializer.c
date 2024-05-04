/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:27 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 16:04:03 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void validate(char *fractol, t_f *frac)
{
    if(ft_strncmp(fractol, "mandelbrot", ft_strlen("mandelbrot")) == 0)
        compiler_mandelbrot(fractol, frac);
    else if(ft_strncmp(fractol, "julia", ft_strlen("julia")) == 0)
        compiler_julia(fractol, frac);
    else
        ft_errors(frac, MAP_INVALID);
}

void compiler_mandelbrot(char *fractol, t_f *frac)
{
    frac->map = mandelbrot;
    frac->x_spam = 3;
	frac->y_spam = 3;
	frac->x_offset = 2.3;
	frac->y_offset = 1.5;
    ft_printf("oi %s\n", fractol);
}

void compiler_julia(char *fractol, t_f *frac)
{
	frac->map = julia;
    ft_printf("oi %s\n", fractol);
}

unsigned int	julia(double c_r, double c_i, void *vars)
{
	printf("%p", vars);
	printf("%f", c_r);
	printf("%f", c_i);
	return(1);
}
