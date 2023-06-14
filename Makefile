# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 19:16:20 by mhernang          #+#    #+#              #
#    Updated: 2023/06/14 14:39:06 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/main.c \
	  src/basic_functions.c \
	  src/basic_functions_2.c \
	  src/check_args.c \
	  src/check_args_utils.c \
	  src/initialize_stacks.c \
	  src/initialize_stacks_utils.c \
	  src/movement_functions.c \
	  src/sort_big_functions.c \
	  src/sort_small_functions.c

OBJ = ${SRC:.c=.o}

LIB = ar rcs

CC = gcc

INCLUDE = push_swap.h

%.o: %.c
	${CC} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDE}
	${LIB} ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclear
