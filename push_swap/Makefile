NAME = push_swap

SRCS =	main.c \
	stack_utils.c \
	atoi_stack.c \
	swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	set_indices.c \
	get_bit.c \
	resolve.c \
	solve_two.c \
	$(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus