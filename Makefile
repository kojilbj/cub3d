CC = cc
CFLAGS = -Wextra -Wall -Werror -fsanitize=address
SRCS = main.c init.c player_control.c validate.c initialize_tex_list.c raycasting.c dda_algorithm.c make_tex_info.c rendering.c

OBJS = $(SRCS:.c=.o)
NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./minilibx -lmlx  -L/usr/X11/lib -lXext -lX11 -lm -o $(NAME)
# -framework OpenGL -framework AppKit	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
