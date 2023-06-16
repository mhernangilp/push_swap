# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 19:16:20 by mhernang          #+#    #+#              #
#    Updated: 2023/06/14 17:02:54 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c \
	   src/basic_functions.c \
	   src/basic_functions_2.c \
	   src/check_args.c \
	   src/check_args_utils.c \
	   src/initialize_stacks.c \
	   src/initialize_stacks_utils.c \
	   src/movement_functions.c \
	   src/sort_big_functions.c \
	   src/sort_small_functions.c \
	   src/ft_split.c

INCLUDE = ./push_swap.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS} $(INCLUDE)
	${CC} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: 
	${RM} ${OBJS}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
