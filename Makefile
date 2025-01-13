NAME = so_long

HEADER  = so_long.h
MLX_LIB = $(MLX_PATH)/libmlx.a

MLX_PATH = ./minilibx
GNL_PATH = ./get_next_line
INC_PATH = -I$(MLX_PATH) -I$(HEADER) -I$(GNL_PATH)

SRC  = main.c \

GNL_SRC = $(GNL_PATH)/get_next_line.c \
          $(GNL_PATH)/get_next_line_utils.c \

ALL_SRC = $(SRC) $(GNL_SRC)
OBJ = $(ALL_SRC:.c=.o)

CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

.c.o:
	@ $(CC) $(CFLAGS) $(INC_PATH) -c $< -o $@

$(NAME): $(OBJ)
	@ $(MAKE) -sC $(MLX_PATH) >/dev/null 2>&1
	@ $(CC) -o $(NAME) $(OBJ) $(MLX_FLAGS)

clean:
	@ $(MAKE) -sC $(MLX_PATH) clean
	@ rm -rf *.o
	@ rm -rf $(GNL_PATH)/*.o

fclean: clean
	@ rm -f $(MLX_LIB)
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
