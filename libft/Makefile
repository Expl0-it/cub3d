# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:51:42 by mamichal          #+#    #+#              #
#    Updated: 2024/03/07 11:29:47 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

# Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./includes/libft.h
RM = rm -fr

# Paths and Files
VPATH = src:bonus
SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c


		#ft_memalloc.c
		#ft_memccpy.c
		#ft_memdel.c
		#ft_strclr.c
		#ft_strcmp.c 
		#ft_strdel.c
		#ft_strmap.c
		#ft_strnew.c
		#ft_strstr.c
		#ft_strsub.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

BONUS_OBJ = $(addprefix obj/,$(BONUS:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

obj:
	mkdir -p obj

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCLUDES) 

clean:
	$(RM) obj 
#	$(RM) bonus_obj

fclean: clean
	$(RM) $(NAME)

re:	fclean all

#bonus_obj:
#	mkdir -p bonus_obj

bonus/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCLUDES) 

bonus: $(OBJ) $(BONUS_OBJ)
	ar r $(NAME) $(OBJ) $(BONUS_OBJ)

.SILENT:

.PHONY: all clean fclean re
