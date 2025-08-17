# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 15:12:41 by cel-hajj          #+#    #+#              #
#    Updated: 2025/08/12 15:53:02 by cel-hajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS = main.c ./srcs/ft_handle_operations.c ./srcs/ft_operations.c ./srcs/ft_putnbr.c ./srcs/utils.c
OBJS = ${SRCS:.c=.o}

HEADER = includes

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
