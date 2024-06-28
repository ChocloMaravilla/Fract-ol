/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/06/28 19:26:08 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "fractol_structs.h"

# define WIDTH 1000
# define HEIGHT	1000
# define ITER 50
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
int 		checking_symbols(char arg);
int			checking_err(char *str);
void		init_win(t_fract *win, t_img *img, char **argv);
void		init_limits(t_screen *screen);
int			iteration_to_scape(t_position c, t_position z, t_fract *vars);
double		ft_atod(char *num);
void		draw_mandelbrot(t_fract *f);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			proportional_trgb(int ampersan, int color, int max_color);
int			proportional_color(int ampersan, int color, int max_color);
t_position	matrix_pos(t_pixel pos, t_screen screen);
#endif
