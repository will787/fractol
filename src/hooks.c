#include "../includes/fractol.h"

static void ft_hook(void *param)
{
	t_f *frac;

	frac = param;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(frac->mlx);
	if (mlx_is_key_down(frac->mlx, MLX_KEY_UP))
		frac->image->instances[0].y -= 50;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_DOWN))
		frac->image->instances[0].y += 50;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT))
		frac->image->instances[0].x -= 50;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_RIGHT))
		frac->image->instances[0].x += 50;
	render(frac);
}

void	close_hook(void *param)
{
	close_program ((t_f *)param, EXIT_SUCCESS);
}