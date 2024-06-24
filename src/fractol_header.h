/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/06/16 03:16:49 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "fractol_structs.h"

# define WIDTH 800
# define HEIGHT	800

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			checking_type_of_set(char *str);
void			lower_case_converter(char *str);
int			checking_arg(int argc, char **argv);
int			ft_isalpha(int c);
size_t			ft_strlen(const char *c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
int 			checking_symbols(char arg);
int			checking_err(char *str);
void			init_win(t_win *win, char *n);
#endif
