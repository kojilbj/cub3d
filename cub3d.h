#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define TEX_SIZE 64
#define WIN_WIDTH 720
#define WIN_HEIGHT 360

#define RAD_PI 180 * M_PI / 180
#define MINUS_RAD_PI -180 * M_PI / 180

#define ESC 65307
#define ROTATE_RIGHT 65363
#define ROTATE_LEFT 65361
#define FORWARD 119
#define BACK 115
#define RIGHT 100
#define LEFT 97

typedef struct	s_node
{
	int	x;
	int	y;
	char	type;
	int	distance;
}	t_node;

typedef struct	s_player
{
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;
}	t_player;

typedef struct	s_info
{
	t_node	**map;
	t_player	player;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	*floor_rgb;
	char	*ceiling_rgb;
}	t_info;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_info	info;
}	t_vars;

void	info_init(t_info *info, char *path);
void	ray_direct(t_info info);

#endif
