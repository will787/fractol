/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:27:51 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 17:07:22 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void render(t_f *frac)
{
    uint32_t j;
    uint32_t i;
    double x;
    double y;
    double z;

    i = -1;
    while (++i < frac->image->width)
    {
        j = -1;
        while (j++ < frac->image->height)
        {
			x = ft_x_value(frac, i);
			y = ft_y_value(frac, j);
			z = frac->map(x,y,frac) * frac->color_factor;
			mlx_put_pixel(frac->image, i, j, circle_cromatic(z, frac->color_scheme));
        }
    }
}

double ft_x_value(const t_f *f, int x_coord)
{
	return ((((double)x_coord / f->image->width) * f->x_spam)
		- f->x_offset);
}

double ft_y_value(const t_f *f, int y_coord)
{
	return (-((((double)y_coord / f->image->height) * f->y_spam)
			- f->y_offset));
}