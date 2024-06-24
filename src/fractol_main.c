/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:10 by rmedina-          #+#    #+#             */
/*   Updated: 2024/06/16 03:47:15 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int invalid_arg(char *arg1){
	int i;
	int flag;

	if (!arg1 || arg1[0] == '\0')
		return (1);
	i = 0;
	flag = 0;
	while(arg1[i])
	{
		if((arg1[i] == '.' && flag == 1) ||\
		(arg1[i] == '.' && arg1[i + 1] == '\0'))
			return (1);
		if(checking_symbols(arg1[i]))
			return (1);
		if(checking_err(arg1))
			return (1);
		if(arg1[i] == '.')
			flag = 1;
		i++;
	}
	return (0);
}

int checking_arg(int argc, char **argv)
{
	lower_case_converter(argv[1]);
	if(!(checking_type_of_set(argv[1])))
		return (0);
	else if(checking_type_of_set(argv[1]) == 1 && argc == 4)
	{	
		if(!argv[2] || !argv[3])
			return (1);
		if(invalid_arg(argv[2]) || invalid_arg(argv[3]))
			return (1);
	}
	else if(checking_type_of_set(argv[1]) == 2)	
		return (0);
	else if(checking_type_of_set(argv[1]) == 3)
		return (0);
	return (0);
}

int main(int argc, char **argv)
{
	t_win win;

	if(argc < 1)
		return(1);
	if(checking_arg(argc, argv))
		exit(1);
	init_win(&win, argv[1]);
	return (0);
}
