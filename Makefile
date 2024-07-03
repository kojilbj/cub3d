CC = cc
#CC += -g -fsanitize=address
CFLAGS = -Wextra -Wall -Werror
SRCS = main.c init_map_info.c \
	rotate_player.c move_player.c \
	validate.c x_func.c \
	color_init1.c color_init2.c \
	file_to_string.c\
	player_init.c texture_init1.c \
	texture_init2.c \
	map_init1.c map_init2.c \
	map_init3.c custom_free.c \
	initialize_tex_list.c \
	raycasting.c \
	dda_algorithm.c \
	make_tex_info.c \
	rendering.c

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
