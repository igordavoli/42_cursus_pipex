.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a
VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --track-children=yes --s
NAME = pipex
SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/pipex.h

NAME_BONUS = pipex_bonus
SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = objects_bonus
HEADER_BONUS = $(SRC_DIR_BONUS)/pipex_bonus.h

SRC_FILES = pipex.c\
	ft_pipex_init.c\
	ft_exec_cmds.c\
	utils/ft_free_pipex.c\
	utils/ft_exit_pipex.c\
	utils/ft_get_cmds.c\
	utils/ft_get_path.c\
	utils/ft_open.c\
	utils/ft_check_args.c\

SRC_FILES_BONUS = pipex_bonus.c\
	ft_pipex_init_bonus.c\
	ft_exec_cmds_bonus.c\
	utils/ft_free_pipex_bonus.c\
	utils/ft_exit_pipex_bonus.c\
	utils/ft_get_cmds_bonus.c\
	utils/ft_get_path_bonus.c\
	utils/ft_open_bonus.c\
	utils/ft_check_args_bonus.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)/utils

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
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME) infile "grep igor" "tr ' ' %" outfile

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(OBJ_BONUS) $(HEADER_BONUS)
	@make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)

$(OBJ_DIR_BONUS):
	mkdir $(OBJ_DIR_BONUS)
	mkdir $(OBJ_DIR_BONUS)/utils

reb:
	@make fclean && make $(NAME_BONUS)

playb: $(NAME_BONUS)
	./$(NAME_BONUS) infile  "grep igor" "wc -l" outfile

playbh: $(NAME_BONUS)
	./$(NAME_BONUS) here_doc eof "grep igor" "wc -l" outfile

valbh: $(NAME_BONUS)
	make reb
	$(VALGRIND) ./$(NAME_BONUS) here_doc eof "grep igor" "wc -l" outfile

valb: $(NAME_BONUS)
	make reb
	$(VALGRIND) ./$(NAME_BONUS) infile "grep igor" "wc -l" outfile
