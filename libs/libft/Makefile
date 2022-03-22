.PHONY: all tests_run clean fclean re

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ./ft_isalpha.c \
	./ft_isdigit.c \
	./ft_isalnum.c \
	./ft_isascii.c \
	./ft_isprint.c \
	./ft_strlen.c \
	./ft_memset.c \
	./ft_bzero.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_strlcpy.c \
	./ft_strlcat.c \
	./ft_toupper.c \
	./ft_tolower.c \
	./ft_strchr.c \
	./ft_strrchr.c \
	./ft_strncmp.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_strnstr.c \
	./ft_atoi.c \
	./ft_calloc.c \
	./ft_strdup.c \
	./ft_substr.c \
	./ft_strjoin.c \
	./ft_strjoin2.c \
	./ft_strtrim.c \
	./ft_split.c \
	./ft_split2/ft_split2.c \
	./ft_itoa.c \
	./ft_strmapi.c \
	./ft_striteri.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
	./ft_free_ptr.c \
	./ft_free_ptrs.c \
	./ft_split2/utils/ft_get_wrd_size.c \
	./ft_split2/utils/ft_count_aps.c \
	./ft_split2/utils/ft_wrd_cnt.c \
	./ft_split2/utils/ft_treat_str_aps.c \
	./ft_split2/utils/ft_get_wrd.c \

SRC_B =./ft_lstnew.c \
	./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c


OBJ_B = $(SRC_B:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ_B)
	ar rcs $(NAME) $(OBJ_B)

tests_run: $(NAME) main.c
	@clang $(CFLAGS) -fsanitize=address -lbsd main.c $(NAME) -o tests.out
	@./tests.out
	@make fclean
	@rm tests.out

clean:
	@find -name '*.o' -delete

fclean:
	make clean
	@rm -rf $(NAME) .tests.out
re:
	make fclean && make all

