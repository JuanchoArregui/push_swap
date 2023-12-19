# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:13:29 by jarregui          #+#    #+#              #
#    Updated: 2023/12/19 11:27:10 by jarregui         ###   ########.fr        #
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

SRCS = main.c $(wildcard utils/*.c args/*.c)
CHECK_SRCS = main.c $(wildcard utils/*.c args/*.c)

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ./libft/${OS_FOLDER}/libft.a ./printf/${OS_FOLDER}/printf.a -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/${OS_FOLDER}/libft.a ./printf/${OS_FOLDER}/printf.a -o ${CHECK}

clean: 
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
