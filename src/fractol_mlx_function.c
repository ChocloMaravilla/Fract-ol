/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:48:22 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/09 17:09:46 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol_header.h"

void	hook_foo(void);

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
