NAME = ft_hexdump.a

SRC = srcs/main.c srcs/utils.c srcs/handle.c srcs/hex_manip/hexdump.c srcs/hex_manip/print.c

INCLUDE = includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

EXEC = ft_hexdump

RM = rm -f

all: $(NAME) $(EXEC)

%.o: %.c
	cc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXEC): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(EXEC)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
	
re: clean all

.PHONY: all clean fclean re