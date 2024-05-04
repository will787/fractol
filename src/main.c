/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:28:19 by wivieira          #+#    #+#             */
/*   Updated: 2024/05/04 11:28:21 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    t_f *frac;
    frac = (t_f *)malloc(sizeof(t_f));
    if(argc != 2)
        ft_errors(frac, TO_MANY_ARGS);
    validate(argv[1],frac);
    window_fractol(frac, argv[1]);
    return(0);
}