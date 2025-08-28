NAME = ft_tail.a

SRC = srcs/main.c srcs/utils.c srcs/errors.c srcs/files/display_file.c srcs/files/file_utils.c srcs/handling/handle_options.c srcs/handling/handle_input.c srcs/print_buffer.c

INCLUDE = includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

EXEC = ft_tail

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