NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Imlx -I./libft
LIBS = -Lmlx -lmlx -L./libft -lft -lX11 -lXext -lm

SRC = main.c \
      ber_check.c \
      ber_check_extra.c \
      get_next_line/*.c \
      loader.c \
      close.c \
      maze_solver.c \
      walls.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_MAKE = $(LIBFT_DIR)/Makefile
MLX_DIR = ./mlx
MLX_MAKE = $(MLX_DIR)/Makefile

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(INCLUDES) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean $(NAME)

