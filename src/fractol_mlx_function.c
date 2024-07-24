/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:48:22 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/24 18:21:39 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol_header.h"

void init_win(t_fract *win, t_img *img,char **argv)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, HEIGHT, WIDTH, argv[1]);
	img->img = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	img->addr= mlx_get_data_addr(img->img, &img->bits_per_pixel\
			, &img->line_length, &img->endian);
	win->img_ptr = img;
	win->iter = ITER;
}

t_position	position_in_square(t_pixel position, t_screen square)
{
	t_position	scale;

	scale.real = (position.x - 0) * (square.fi_x - square.im_x) / (WIDTH - 0)
		+ square.im_x;
	scale.im = (position.y - 0) * (square.fi_y - square.im_y) / (HEIGHT - 0)
		+ square.im_y;

	return (scale);
}

void	init_limits(t_screen *square)
{
	square->im_x = -1;
	square->fi_x =  1;
	square->im_y = -1;
	square->fi_y =  1;
}
