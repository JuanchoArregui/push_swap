# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:13:29 by jarregui          #+#    #+#              #
#    Updated: 2024/03/18 21:58:39 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker


OS := $(shell uname -s)
ifeq ($(OS),Linux) # Estamos en Linux
	OS_FOLDER = linux
endif
ifeq ($(OS),Darwin) # Darwin es para macOS
	OS_FOLDER = mac
endif
ifeq ($(OS),Windows) # Estamos en windows
	OS_FOLDER = windows
endif

# SRCS =  $(wildcard src/*.c utils/*.c)
# CHECK_SRCS = $(wildcard utils/*.c) src/instructions.c checker.c

SRCS = main.c $(wildcard my_files/*.c)
CHECK_SRCS = checker.c $(wildcard my_files/*.c) $(wildcard my_libs/get_next_line/*.c)

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# use this for debugging:
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# use this for memmory leaks:
# CFLAGS = -Wall -Wextra -Werror -g
# valgrind --leak-check=full ./push_swap 3 2 1 9 5 4 8 7 6

RM = rm -rf

# all: ${NAME} ${CHECK}
all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ./my_libs/libft/${OS_FOLDER}/libft.a ./my_libs/printf/${OS_FOLDER}/printf.a -o ${NAME}

# ${CHECK}: ${CHECK_OBJS} 
# 	@${CC} ${CFLAGS} ${CHECK_OBJS} ./my_libs/libft/${OS_FOLDER}/libft.a ./my_libs/printf/${OS_FOLDER}/printf.a -o ${CHECK}

clean: 
	@${RM} ${OBJS}
# 	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
#	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
