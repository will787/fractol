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

void	window_fractol(t_f *frac, char *map)
{
	frac->mlx = NULL;
	frac->image = NULL;
	validate(map,frac);
	frac->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", false);
	if (!frac->mlx)
		ft_errors(frac, MLX_FAILURE);
	frac->image = mlx_new_image(frac->mlx, frac->mlx->width, frac->mlx->height);
	if (!frac->image || mlx_image_to_window(frac->mlx, frac->image, 0, 0) < 0)
		ft_errors(frac, MLX_IMAGE_FAIL);
	frac->iters = ITERS;
	frac->zoom = 1.0;
	frac->color_factor = color_factor(frac);
	frac->color_scheme = black_white;
}

void	key_move(void *param)
{
	t_f	*fractol;

	fractol = (t_f *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->image->instances[0].y -= 50;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->image->instances[0].y += 50;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->image->instances[0].x -= 50;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->image->instances[0].x += 50;
}
