.PHONY: all clean fclean re

SRC_DIR = source/

CHECKER = checker

SRC_CH = source/checker.c

OBJ_CH = $(SRC_CH:.c=.o)

PUSH_SWAP = push_swap

SRC_PS = $(addprefix $(SRC_DIR),\
		push_swap.c under_five.c \
		mid_sort.c init_index.c \
		print_oper.c del_diff.c \
		dop_funk.c)

OBJ_PS = $(SRC_PS:.c=.o)

SRC_BASE = $(addprefix $(SRC_DIR),\
		swap_funk.c rotate_funks.c dop_funk_2.c\
		reverse_rotate_funks.c read_input.c)

OBJ_BASE = $(SRC_BASE:.c=.o)

LIB = libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = include/push_swap.h

all: $(LIB) $(PUSH_SWAP) $(CHECKER)

$(LIB):
	make -C libft/

$(PUSH_SWAP): $(OBJ_PS) $(OBJ_BASE) $(LIB)
	$(CC) $^ $(LIB) -o $@

$(OBJ_PS): $(HEADER)

$(OBJ_BASE): $(HEADER)

$(CHECKER): $(OBJ_CH) $(OBJ_BASE) $(LIB)
	$(CC) $^ $(LIB) -o $@

$(OBJ_CH): $(HEADER)

clean:
	make clean -C libft
	rm -rf source/*.o

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(LIB)

re: fclean all