# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 19:50:14 by mbudkevi          #+#    #+#              #
#    Updated: 2025/05/05 17:36:22 by mbudkevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MY_SOURCES = ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_split.c \
			get_next_line.c \
			print_char.c \
			print_hexadecimal.c \
			print_int.c \
			print_pointer.c \
			print_string.c \
			print_unsigned_d.c \
			ft_printf.c \
			ft_multi_split.c \
			ft_free_split.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = libft.a

CC = gcc

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all	
	
