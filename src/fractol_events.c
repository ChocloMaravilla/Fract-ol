/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:37:29 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/28 23:41:14 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int key_hook(int keycode, t_fract *fractal)
{
	if(keycode == B_Escape)
		printf("la\n");
		//close_handler(fractal);
	else if(keycode == B_Left || keycode == B_A)
	{
		printf("B_1\n");
		fractal->matrix.im_x += 0.5f;
		fractal->matrix.fi_x += 0.5f;
	}
	else if(keycode == B_Right || keycode == B_D)
	{
		fractal->matrix.im_x -= 0.5f;
		fractal->matrix.fi_x -= 0.5f;
		printf("B_2\n");
	}
	else if(keycode == B_Up || keycode == B_W)
	{
		fractal->matrix.im_y += 0.5f;
		fractal->matrix.fi_y += 0.5f;
		printf("B_3\n");
	}
	else if(keycode == B_Down || keycode == B_S)
	{
		fractal->matrix.im_y -= 0.5f;
		fractal->matrix.fi_y -= 0.5f;
		printf("B_4\n");
	}
	else if(keycode == B_Plus)
	{
		//fractal->iter += 10;
		printf("B_5\n");
	}
	else if(keycode == B_Minus)
	{
		//fractal->iter -= 10;
		printf("B_6\n");
	}
	else
		return (0);
	if(ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if(ft_strncmp(fractal->name, "julia", 5) == 0)
		printf("julia\n");
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr->img, 0, 0);
	return (0);
}
