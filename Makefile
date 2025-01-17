CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux
TEX_DIR = textures
MAP_DIR = maps
PRINTF_DIR = ft_printf

SRC_FILES = $(SRC_DIR)/main.c \
            $(GNL_DIR)/get_next_line.c \
            $(GNL_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/keyhook.c \
			$(SRC_DIR)/check_utils.c \
			$(SRC_DIR)/mlx_image_utils.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/check_map.c \
			$(SRC_DIR)/valid_path.c \
			$(SRC_DIR)/exit.c \
			$(SRC_DIR)/check_walls.c \
			$(SRC_DIR)/keyhook_utils.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

MLX_LIB = $(MLX_DIR)/libmlx.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx -L$(PRINTF_DIR) -lftprintf -lX11 -lXext -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ_FILES)
	@make clean -C $(MLX_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
