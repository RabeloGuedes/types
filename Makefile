COMP = cc
CFLAGS = -Wall -Wextra -Werror -g

INC = -I ./includes
NAME = libtypes

SRC_FOLDER = srcs/
SRC_FILES = typestr.c
OBJ_FOLDER = objs/
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

