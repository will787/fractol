/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:39 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 15:59:23 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	color_factor(t_f *frac)
{
	return (1 / (frac->iters));
}

double	black__white(double n)
{
    n = 1 - n;
    n *= 255;
    return(color_rgba(n, n, n, 255));
}


double	circle_cromatic(double n, int cromatic)
{
    if(cromatic == black_white)
        return (black__white(n));
    return -1;
}

double	crazy_dynamic_scheme(double nb)
{
	int		r;
	int		g;
	int		b;
	double	time;

	time = mlx_get_time();
	if (time > 10000)
		time = 10000;
	nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * mlx_get_time();
	r = (sin(nb) + 1) / 2 * 255;
	g = (int)nb % 255;
	b = (int)(nb / 1.61803398875) % 255;
	return (color_rgba(r, g, b, 255));
}