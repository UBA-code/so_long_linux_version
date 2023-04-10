SRCS = game.c put_line_to_window.c get_next_line_utils.c get_next_line.c \
		game_utils.c get_map.c render_map.c check_map.c check_map_two.c check_path.c \
		messages.c \
		move_up.c move_enemy.c
CFLAGS = -Wall -Werror -Wextra -lX11 -lXext -lmlx
OBGS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBGS)
	$(CC) -o $(NAME) $(OBGS) $(CFLAGS) 
clean:
	rm -rf $(OBGS)

fclean: clean
	rm -rf $(NAME)

re: fclean all