NAME = fractol
SRC = src/fractol_main.c src/fractol_checking.c src/fractol_mlx_function.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_A = Libs/ft_libft/libft.a
MLX_A = mlx_linux/libmlx_Linux.a
all: makelibft makemlx $(NAME)
makelibft:
	make -C Libs/ft_libft
makemlx:
	make -C mlx_linux
$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	${CC} $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME)
# -L mlx_test -I mlx_test
%.o:%.c Makefile fractol_macros.h fractol_structs.h
	${CC} $(CFLAGS) -c $< -o $@
# -Imlx_linux/mlx.h
clean:
	$(RM) $(OBJS)
	make clean -C Libs/ft_libft
	make clean -C mlx_linux
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re makelibft
