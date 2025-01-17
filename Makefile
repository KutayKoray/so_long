CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux
TEX_DIR = textures
MAP_DIR = maps

SRC_FILES = $(SRC_DIR)/main.c \
            $(GNL_DIR)/get_next_line.c \
            $(GNL_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/keyhook.c \
			$(SRC_DIR)/check_utils.c \
			$(SRC_DIR)/mlx_image_utils.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/check_map.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx -lX11 -lXext -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJ_FILES)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re