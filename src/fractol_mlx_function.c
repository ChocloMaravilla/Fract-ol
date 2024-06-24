
#include "fractol_header.h"

void init_win(t_win *win, char *n)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, n);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->addr_ptr= mlx_get_data_addr(win->img_ptr, &win->bits_per_pixel, &win->size_line, &win->endian);
}

