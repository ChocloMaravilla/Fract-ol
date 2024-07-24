/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/24 18:13:48 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "fractol_structs.h"
# include <math.h>

# define WIDTH 1000
# define HEIGHT	1000
# define NOT_IN_RANGE 2147483647
# define ITER 100
# define TURQUESA 0x03FC90
# define ROSE 0xFC036F

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			checking_type_of_set(char *str);
void		lower_case_converter(char *str);
int			checking_arg(int argc, char **argv);
int			ft_isalpha(int c);
size_t		ft_strlen(const char *c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			checking_symbols(char arg);
int			checking_next_char(char *str);
void		init_win(t_fract *win, t_img *img, char **argv);
void		init_limits(t_screen *screen);
int			iteration_to_scape(t_position c, t_position z, int iter);
double		ft_atod(char *num);
void		draw_mandelbrot(t_fract *vars);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			proportional_trgb(int percentage, int color, int max_color);
int			proportional_color(int percentage, int color, int max_color);
t_position	matrix_pos(t_pixel pos, t_screen screen);
int			is_in_buffer(char *buf, char c);
t_position	position_in_square(t_pixel position, t_screen square);
#endif
