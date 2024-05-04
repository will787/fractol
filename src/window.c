/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:05 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 11:34:08 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	window_fractol(t_f *frac, char *map)
{
	frac->mlx = NULL;
	frac->image = NULL;
	frac->mlx = mlx_init(WIDTH, HEIGHT, map, true);
	if (!frac->mlx)
		return ;
	frac->image = mlx_new_image(frac->mlx, frac->mlx->width, frac->mlx->height);
	if (!frac->image)
		ft_errors(frac, MLX_IMAGE_FAIL);
	if (mlx_image_to_window(frac->mlx, frac->image, 0, 0) < 0)
		ft_errors(frac, MLX_FAILURE);
	frac->iters = ITERS;
	frac->zoom = 1;
	frac->color_proto = color_factor(frac);
	frac->colors_pixel = black_white;
	mlx_close_hook(frac->mlx, key_move, frac);
	mlx_loop(frac->mlx);
	mlx_terminate(frac->mlx);
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
