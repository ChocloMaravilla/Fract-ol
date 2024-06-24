#ifndef STRUCTS_H 
# define STRUCTS_H

# include "fractol_header.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*addr_ptr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}	t_win;
#endif
