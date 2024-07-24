/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:10 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/24 15:53:37 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

double ft_atod(char *num)
{
	int i;
	int sign;
	double nbr;

	i = 0;
	sign = -1;
	nbr = 0;
	if (num[0])
	{
		sign = -1;
		i++;
	}
	while(num[i])
	{
		nbr = nbr * 10 + num[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int invalid_arg(char *arg1){
	t_var vars = {0, 0};
	char buf[3];

	if (!arg1 || arg1[0] == '\0')
		return (1);
	while(arg1[vars.i])
	{
		if (!is_in_buffer(buf, arg1[vars.i]))
		{
			buf[vars.j] = arg1[vars.i];
			vars.j++;
			vars.i++;
		}
		else
			vars.i++;
		if (arg1[vars.i] == '.' && arg1[vars.i + 1] == '\0')
			return (1);
		if (checking_symbols(arg1[vars.i]) || checking_next_char(arg1))
			return (1);
		vars.i++;
	}
	return (0);
}
int is_in_buffer(char *buf, char c)
{
	int i;

	i = 0;
	while(buf[i])
	{
		if(buf[i] == c || !checking_symbols(c))
			return (1);
		i++;
	}
	return (0);
}

int checking_arg(int argc, char **argv)
{
	int type_of_set;

	if (argv[1] == NULL)
		return (1);
	lower_case_converter(argv[1]);
	type_of_set = checking_type_of_set(argv[1]);
	if (!type_of_set)
		return (1);
	if (type_of_set == 2 && argc == 4)
	{	
		if(!argv[2] || !argv[3])
			return (1);
		if(invalid_arg(argv[2]) || invalid_arg(argv[3]))
			return (1);
		return (0);
	}
	else if (type_of_set == 3 && argc == 2)	
		return (0);
	else if (type_of_set == 4 && argc == 2)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_fract	fractal;
	t_img	img;

	if (argc < 1)
		return(1);
	if (checking_arg(argc, argv))
		exit(1);
	init_limits(&fractal.matrix);
	init_win(&fractal, &img, argv);
	if (checking_type_of_set(argv[1]) == 2)
		return (0);
		//draw_julia(&fractal);
	else if (checking_type_of_set(argv[1]) == 3)
		draw_mandelbrot(&fractal);
	else if (checking_type_of_set(argv[1]) == 4)
		return (0);
		//draw_tricorn();
	
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.win_ptr, img.img, 0, 0);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
