.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a
# FT_PRINTF = libs/ft_printf/libftprintf.a


NAME = pipex
SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/pipex.h

# NAME_BONUS = so_long_bonus
# SRC_DIR_BONUS = src_bonus
# OBJ_DIR_BONUS = objects_bonus
# HEADER_BONUS = $(SRC_DIR_BONUS)/so_long_bonus.h

SRC_FILES = pipex.c\
	utils/gnl/get_next_line.c\
	utils/gnl/get_next_line_utils.c\
	utils/ft_free_pipex.c\
	utils/ft_exit_pipex.c\
	utils/ft_get_cmds.c\
	utils/ft_get_path.c\
	utils/ft_open.c\
	ft_partial_print.c\
	ft_pipex_init.c\
	ft_exec_cmds.c\

# SRC_FILES_BONUS = so_long_bonus.c\
# 	ft_get_sprites_bonus.c\
# 	ft_key_handler_bonus.c\
# 	ft_close_bonus.c\
# 	ft_close_message_bonus.c\
# 	ft_get_map_bonus.c\
# 	ft_put_map_bonus.c\
# 	ft_check_args_bonus.c\
# 	utils_bonus/ft_move_hero_bonus.c\
# 	utils_bonus/ft_load_map_bonus.c\
# 	utils_bonus/check_map_utils_bonus.c\
# 	utils_bonus/ft_check_map_bonus.c\
# 	utils_bonus/ft_put_moves_win.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))
# OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
# make -C ./libs/ft_printf
	make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

# $(NAME_BONUS): $(OBJ_DIR_BONUS) $(OBJ_BONUS) $(HEADER_BONUS)
# 	make -C ./libs/gnl
# 	make -C ./libs/libft
# 	make -C ./libs/minilibx
# 	make -C ./libs/ft_printf
# 	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(MLX) $(MLX_FLAGS) $(GNL) $(FT_PRINTF) $(LIBFT)

clean:
	rm -rf objects*

fclean:
	make  clean
	find -name '$(NAME)' -delete
	find -name '$(NAME_BONUS)' -delete

re:
	@make fclean && make all

test: all
	./$(NAME) infile  "grep igor" "wc -l" outfile

val: all
	make re
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME) infile "grep 'igor'" "wc -l" outfile

# reb:
# 	@make fclean && make $(NAME_BONUS)

$(OBJ_DIR):
	mkdir objects
	mkdir objects/utils
	mkdir objects/utils/gnl
	mkdir objects/utils/libft

# bonus: $(NAME_BONUS)

# playb: $(NAME_BONUS)
# 	./$(NAME_BONUS) maps/map_bonus.ber

# valb: $(NAME_BONUS)
# 	make reb
# 	valgrind --track-origins=yes --leak-check=full -s ./$(NAME_BONUS) maps/map_bonus.ber

# $(OBJ_DIR_BONUS):
# 	mkdir objects_bonus
# 	mkdir objects_bonus/utils_bonus
