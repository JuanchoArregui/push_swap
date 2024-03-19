# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2024/03/19 16:24:39 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
ARFLAGS		=	rcs
NAME		=	printf.a
RM			=	/bin/rm -f
EXEC_NAME	=	a.out

# IMPORTANTE: ESTA PROHIBIDO USAR WILDCARD EN EL MAKEFILE
# SEGUN LA NORMA HAY QUUE EXPLICITAR TODOS Y CADA UNOO DE LOS ARCHIVOS DEL CODIGO FUENTE
SRCS		=	$(wildcard functions/*.c)

OBJS		=	${SRCS:.c=.o}

# RULES DECLARATION:
all:			${NAME}

${NAME}:		${OBJS}
					ar -rc ${NAME} ${OBJS}
					ranlib ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS} ${EXEC_NAME}

fclean:			clean
					${RM} ${NAME}
 
re:				fclean all

.PHONY:			all clean fclean re bonus