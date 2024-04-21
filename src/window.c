#include "../includes/fractol.h"

void window_fractol(t_f *fractol, char *map)
{
    fractol->mlx = mlx_init(WIDTH, HEIGHT, map, true);
    if(!fractol->mlx)
        return ;
    fractol->image =mlx_new_image(fractol->mlx, 600, 600);
    if(!fractol->image)
        return ;
    if(mlx_image_to_window(fractol->mlx, fractol->image, 150, 200))
    {
        mlx_close_window(fractol->mlx);
        puts(mlx_strerror(mlx_errno));
        return ;
    }
    mlx_close_hook(fractol->mlx, key_move, fractol);
    mlx_loop(fractol->mlx);
    mlx_terminate(fractol->mlx);
}

void key_move(void* param)
{
	t_f *fractol;

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