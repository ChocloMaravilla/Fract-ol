/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:37:29 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/28 03:28:06 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int key_handler(int keysym, t_fract *fractal)
{
	if(keysym == B_Escape)
		close_handler(fractal);
	else if(keysym == B_Left)
		fractal->button_x += 0.5;
	else if(keysym == B_Right)
		fractal->button_y -= 0.5;
	else if(keysym == B_Up)
		fractal->button_y += 0.5;
	else if(keysym == B_Down)
		fractal->button_y -= 0.5;
	else if(keysym == B_plus)
		fractal->iter += 10;
	else if(keysym == B_minus)
		fractal->iter -= 10;
	return (0);
}
