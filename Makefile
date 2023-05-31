# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 19:16:20 by mhernang          #+#    #+#              #
#    Updated: 2023/05/31 19:58:02 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/main.c \
	  src/exit_program.c \
	  src/check_args.c

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
