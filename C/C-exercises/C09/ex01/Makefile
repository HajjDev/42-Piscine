LIBRARY = libft.a

SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}

HEADER = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${LIBRARY}: ${OBJS}
	ar rcs ${LIBRARY} ${OBJS}

all: ${LIBRARY}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${LIBRARY}

re: fclean all