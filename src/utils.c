/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:27:59 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 16:40:12 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_errors(t_f *frac, int type_er)
{
	if (type_er == MAP_INVALID)
		ft_putstr_fd("Map invalid, please select correctly map\n", 1);
	else if (type_er == TO_MANY_ARGS)
		ft_putstr_fd ("Arguments for necessary the compiler: ./fractol {map}\n", 1);
	else if (type_er == MLX_FAILURE)
		ft_putstr_fd("Creation failure mlx window\n", 1);
	else if (type_er == MLX_IMAGE_FAIL)
		ft_putstr_fd("Failure view image, try again\n", 1);
	close_program (frac, EXIT_FAILURE);
}

void close_program(t_f *frac, int type_er)
{
    if(frac->image)
        mlx_delete_image(frac->mlx, frac->image);
    if(frac->mlx)
    {
        mlx_close_window(frac->mlx);
        mlx_terminate(frac->mlx);
    }
    exit(type_er);
}

void zoom_in(t_f *frac)
{
    double previous;

    previous = frac->x_spam;
    frac->x_spam *= 0.99;
    frac->x_offset -= (previous - frac->x_spam)  / 2;
    previous = frac->y_spam;
    frac->y_spam *= 0.99;
    frac->y_offset *= (previous - frac->y_spam) / 2;
    frac->zoom /= 0.99;
}

void zoom_out(t_f *frac)
{
    double previous;

    previous = frac->x_spam;
    frac->x_spam *= 1.01;
    frac->x_offset = (previous - frac->x_spam) / 2;
    previous = frac->y_spam;
    frac->y_spam -= (previous - frac->y_spam) / 2;
    frac->zoom /= 1.01;
}


void many_colors(t_f *frac)
{
    frac->x_seed = 0.291892;
	frac->y_seed = 0.016842;
    while ((frac->x_seed / 100) < frac->iters)
    {
        while (frac->y_seed / 100 < frac-> iters / 20)
        {
            frac->y_seed += frac->y_seed / 50;
            break;
        }
        frac->x_seed += frac->x_seed / 50;
    }
}