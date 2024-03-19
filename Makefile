# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:13:29 by jarregui          #+#    #+#              #
#    Updated: 2024/03/19 12:47:56 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c $(wildcard my_files/*.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# use this for debugging:
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# use this for memmory leaks:
# CFLAGS = -Wall -Wextra -Werror -g
# valgrind --leak-check=full ./push_swap 3 2 1 9 5 4 8 7 6

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./my_libs/libft
	@${MAKE} -C ./my_libs/printf
	@${CC} ${CFLAGS} ${OBJS} ./my_libs/libft/libft.a ./my_libs/printf/printf.a -o ${NAME}

clean: 
	@${RM} ${OBJS}
# @${MAKE} -C ./my_libs/libft clean
# @${MAKE} -C ./my_libs/printf clean

fclean: clean
	@${RM} ${NAME}
# @${MAKE} -C ./my_libs/libft fclean
# @${MAKE} -C ./my_libs/printf fclean

re: fclean all

.PHONY: all clean fclean re
