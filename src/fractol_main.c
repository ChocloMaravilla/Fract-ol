/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:10 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/22 19:56:12 by rmedina-         ###   ########.fr       */
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
	int i;
	int j;
	/*int flag;*/
	char buf[2];

	if (!arg1 || arg1[0] == '\0')
		return (1);
	/*flag = 0;*/
	i = 0;
	j = 0;
	if (is_in_buffer(arg1[i]))
	{
		buf[j] == arg1[i];
		j++;
:q
:q
exit
		i++;
	}
	/*while (sea digit(arg1[i]))
	{
		i++;
	}*/
	while(arg1[i])
	{
		if ((arg1[i] == '.' && flag == 1) ||\
		(arg1[i] == '.' && arg1[i + 1] == '\0'))
			return (1);
		if (checking_symbols(arg1[i]))
			return (1);
		if (checking_err(arg1))
			return (1);
		if (arg1[i] == '.')
			flag = 1;
		i++;
	}
	return (0);
}
int is_in_buffer(char *buf, char c)
{
	int i;

	i = 0
	while(buf[i])
	{
		if(buf[i] && buf[i] == c)
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
