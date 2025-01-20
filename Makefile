NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
IFLAGS = -I ./includes -I ./libft -I ./minilibx-linux
RM = rm -fr
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS = $(wildcard src/*.c)
#, $(wildcard src/*/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(IFLAGS) $(MLXFLAGS)

%.o: %.c $(LIBFT)
	make -C $(MLX_PATH) all
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_PATH} all

# $(MLXLIB):
# 	make -C $(MLX_PATH) all

clean:
	rm -f $(OBJS)
	make -C ${LIBFT_PATH} fclean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
