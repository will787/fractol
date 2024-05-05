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

double	black__white_theme(double n)
{
    n = 1 - n;
    n *= 255;
    return(color_rgba(n, n, n, 255));
}

double black__other_theme(double n)
{
    int r;
	int g;
	int b;
	int a;
    if (n == 0) {
        r = 255; // Vermelho
        g = 0;
		b = 0; // Zerar as outras componentes para garantir vermelho puro
    }
    else if (n == 1) {
        r = g = b = 0; // Preto
        a = 255; // Opaco
    }
    else {
        // Use alguma lógica para calcular R, G, B e A com base em N
        // Aqui você pode implementar a lógica para as outras cores se necessário
    }
    return color_rgba(r, g, b, a);
}



double	circle_cromatic(double n, int cromatic)
{
    if(cromatic == black_white)
        return (black__white_theme(n));
	else if(cromatic == black_red)
		return (black__other_theme(n));
    return -1;
}