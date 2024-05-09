/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:05 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 17:15:10 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	window_fractol(t_f *frac, char *argv)
{
	frac->mlx = NULL;
	frac->image = NULL;
	validate(argv,frac);
	frac->mlx = mlx_init(WIDTH, HEIGHT, ft_strjoin("Fractol | ", argv), false);
	if (!frac->mlx)
		return (ft_errors(frac, MLX_FAILURE));
	frac->image = mlx_new_image(frac->mlx, frac->mlx->width, frac->mlx->height);
	if (!frac->image || mlx_image_to_window(frac->mlx, frac->image, 0, 0) < 0)
		return (ft_errors(frac, MLX_IMAGE_FAIL));
	frac->iters = ITERS;
	frac->zoom = 1.0;
	frac->color_factor = color_factor(frac);
	frac->color_scheme = black_white;
}
