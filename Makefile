NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
IFLAGS = -I ./includes -I ./libftPrintfGnl -I ./minilibx-linux
RM = rm -fr
#LIBFT_PATH = ./libft
LIBFTGNL_PATH = ./libftPrintfGnl
#LIBFT = $(LIBFT_PATH)/libft.a
LIBGTGNL = $(LIBFTGNL_PATH)/libftPrintfGnl.a
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS = src/main.c \
	   $(wildcard src/*/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBGTGNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTGNL) $(MLX) $(IFLAGS) $(MLXFLAGS)

%.o: %.c $(LIBFTGNL)
	make -C $(MLX_PATH) all
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


${LIBFTGNL}:
	make -C ${LIBFTGNL_PATH} all

# $(MLXLIB):
# 	make -C $(MLX_PATH) all

clean:
	rm -f $(OBJS)
	make -C ${LIBFTGNL_PATH} fclean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
