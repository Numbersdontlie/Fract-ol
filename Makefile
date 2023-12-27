NAME = fractol

SRCS = events.c init.c main.c utils.c mandelbrot.c julia.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = minilibx-linux
MLX = minilibx-linux/libmlx.a
LIB = fractol.h

all: ${NAME} ${MLX}

$(NAME): $(OBJS)
		@make -C $(MLX_PATH)
		cc $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)
		@echo "$(NAME): $(OBJS) was created"

clean:
		rm -rf $(OBJS)
		@make clean -C $(MLX_PATH)
		@echo "$(NAME): $(OBJS) was deleted"

fclean: clean
		rm -rf $(NAME) $(MLX)
		@echo "$(NAME) $(MLX) was deleted"

re: fclean all

.PHONY: all clean fclean re