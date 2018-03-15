# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 20:32:20 by ddenkin           #+#    #+#              #
#    Updated: 2018/03/09 20:32:22 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

LIBNAME = libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SRC =	main.c \
        src/output.c \
        src/ai.c \
        src/utils.c \
        src/color_text.c

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
