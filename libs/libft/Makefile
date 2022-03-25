.PHONY: all tests_run clean fclean re

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/libft.h

SRC_FILES = ./ft_strlcat.c \
	./ft_strlcpy.c \
	./ft_striteri.c \
	./ft_strrchr.c \
	./ft_isdigit.c \
	./ft_substr.c \
	./ft_memcmp.c \
	./ft_memchr.c \
	./ft_calloc.c \
	./ft_putendl_fd.c \
	./ft_memmove.c \
	./ft_putnbr_fd.c \
	./ft_split2/utils/ft_get_wrd_size.c \
	./ft_split2/utils/ft_count_aps.c \
	./ft_split2/utils/ft_treat_str_aps.c \
	./ft_split2/utils/ft_get_wrd.c \
	./ft_split2/utils/ft_wrd_cnt.c \
	./ft_split2/ft_split2.c \
	./ft_isprint.c \
	./ft_printf/ft_resolve_dec.c \
	./ft_printf/ft_resolve_chr.c \
	./ft_printf/ft_resolve_str.c \
	./ft_printf/ft_resolve_flg.c \
	./ft_printf/ft_resolve_ptr.c \
	./ft_printf/ft_resolve_uns.c \
	./ft_printf/ft_resolve_hex.c \
	./ft_printf/ft_printf_puts.c \
	./ft_printf/ft_printf.c \
	./ft_printf/ft_printf_utils.c \
	./ft_free_ptr.c \
	./ft_strtrim.c \
	./ft_putstr_fd.c \
	./ft_lstmap.c \
	./ft_strjoin2.c \
	./ft_lstdelone.c \
	./ft_lstadd_back.c \
	./get_next_line.c \
	./ft_tolower.c \
	./ft_strncmp.c \
	./ft_isascii.c \
	./ft_bzero.c \
	./ft_putchar_fd.c \
	./ft_lstsize.c \
	./ft_load_file.c \
	./ft_toupper.c \
	./ft_strchr.c \
	./ft_lstnew.c \
	./ft_itoa.c \
	./ft_lstiter.c \
	./ft_atoi.c \
	./ft_memset.c \
	./ft_strmapi.c \
	./ft_isalnum.c \
	./ft_memcpy.c \
	./ft_split.c \
	./ft_strjoin.c \
	./ft_strnstr.c \
	./ft_lstlast.c \
	./ft_free_ptrs.c \
	./ft_isalpha.c \
	./ft_lstclear.c \
	./ft_strdup.c \
	./ft_lstadd_front.c \
	./ft_strlen.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir objects
	mkdir objects/ft_printf
	mkdir objects/ft_split2
	mkdir objects/ft_split2/utils

bonus: $(OBJ_B)
	ar rcs $(NAME) $(OBJ_B)

clean:
	@rm -rf objects

fclean:
	make clean
	@rm -rf $(NAME)
re:
	make fclean && make all

