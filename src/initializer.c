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

void validate(char *argv, t_f *frac)
{
    if(ft_strncmp("mandelbrot", argv, ft_strlen("mandelbrot")) == 0)
        compiler_mandelbrot(argv, frac);
    else if(ft_strncmp(argv, "julia", ft_strlen("julia")) == 0)
        compiler_julia(argv, frac);
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
    ft_printf("oi%s\n", fractol);
}

void compiler_julia(char *fractol, t_f *frac)
{
	frac->map = julia;
    frac->x_spam = 3.2;
    frac->y_spam = 3.2;
    frac->x_offset = 1.6;
    frac->y_offset = 1.6;
    frac->x_seed = 0.291892;
	frac->y_seed = 0.016842;
    ft_printf("oi %s\n", fractol);
}
