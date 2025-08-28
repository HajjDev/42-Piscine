NAME = bsq.a

SRC = srcs/free.c \
	srcs/main.c \
	srcs/map/max_element.c \
	srcs/map/modify.c \
	srcs/map/parser/parser.c \
	srcs/map/parser/parser_utils.c \
	srcs/dp/transform/transform_utils.c \
	srcs/map/parser/parser_utils2.c \
	srcs/map/print.c \
	srcs/dp/solve/solve_utils.c \
	srcs/dp/solve/solve.c \
	srcs/dp/transform/transform.c \
	srcs/utils.c

INCLUDE = includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

EXEC = bsq

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
	$(RM) $(EXEC)
	
re: clean all

.PHONY: all clean fclean re