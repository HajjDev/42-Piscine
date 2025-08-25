# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 15:32:15 by cel-hajj          #+#    #+#              #
#    Updated: 2025/08/25 18:19:53 by cel-hajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC =	main.c \
		error.c \
		utils.c \
		converter.c \
		converter_utils.c \
		dict_parser.c \
		dict_parser_count.c \
		dict_parser_helpers.c \
		dict_parser_utils.c \
		dict_utils.c \
		handle_input.c \
		bigint_operations.c \
		bigint_div.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "rush-02 a été creer."

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
