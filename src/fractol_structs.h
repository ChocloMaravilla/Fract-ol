#ifndef STRUCTS_H 
# define STRUCTS_H

typedef struct s_pixel
{
	int x;
	int y;
	int color;
}	t_pixel;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_screen
{	
	int	im_x;
	int fi_x;
	int im_y;
	int fi_y;
} t_screen;

typedef struct s_position
{
	float	real;
	float	im;
}	t_position;

typedef struct s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	int			iter;
	t_screen	matrix;
	t_position	c;
	t_position	z;
}	t_fract;	

#endif
