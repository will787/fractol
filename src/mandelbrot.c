/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:13 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 11:36:12 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	mandelbrot(double c_r, double c_i, void *vars)
{
	unsigned int	n;
	double			z_r;
	double			z_i;
	double			tmp;
	t_f				*fractol;

	fractol = vars;
	z_r = 0.0;
	z_i = 0.0;
	n = -1;
	while (++n < fractol->iters)
	{
		if ((z_r * z_r + z_i * z_i) > 4.0)
			break ;
		tmp = calculate_z_i(z_r, z_i, c_i);
		z_r = calculate_z_r(z_r, z_i, c_r);
		z_i = tmp;
	}
	return (n);
}

double calculate_z_r(double z_r, double z_i, double c_r)
{
	return (pow(z_r, 2) - pow(z_i, 2) + c_r);
}

double calculate_z_i(double z_r, double z_i, double c_i)
{
	return 2 * z_r * z_i + c_i;
}