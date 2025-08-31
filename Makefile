COMP = c++
CFLAGS = -Wall -Wextra -Werror -g

INC = -I ./includes
NAME = libtypes

MAIN = main.cpp

SRC_DIR = srcs/
NUMBER_DIR = $(SRC_DIR)number/
SRC_FILES = $(NUMBER_DIR)Number.cpp
OBJ_DIR = objs/
OBJ_FILES = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "compiling: $< -> $@"
	@$(COMP) -c $(CFLAGS) $(INC) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) $(MAIN:%.cpp=%)

re: fclean all

prog: $(MAIN)

$(MAIN): all
	$(COMP)  $(INC) $(SRC_DIR)$(MAIN) -o $(MAIN:%.cpp=%) $(NAME)
