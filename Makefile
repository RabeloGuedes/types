COMP = cc
CFLAGS = -Wall -Wextra -Werror -g

INC = -I ./includes
NAME = libtypes

SRC_DIR = srcs/
STRING_DIR = $(SRC_DIR)string/
SRC_FILES = $(STRING_DIR)typestr.c
OBJ_DIR = objs/
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "compiling: $< -> $@"
	@$(COMP) -c $(CFLAGS) $(INC) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

