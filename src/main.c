/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:19 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 17:15:43 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    t_f	frac;
    if(argc != 2)
	{
		ft_putstr_fd("compiler, with ./fractol map\n", 1);
		return(EXIT_FAILURE);
	}
    window_fractol(&frac, argv[1]);
	mlx_close_hook(frac.mlx, &close_hook, &frac);
    mlx_loop_hook(frac.mlx, ft_hook, &frac);
	//mlx_key_hook(frac.mlx, &mouse_hook, &frac);
	//mlx_scroll_hook(frac.mlx, &scroll_hook, &frac);
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return(0);
}
