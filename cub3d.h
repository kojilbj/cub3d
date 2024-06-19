#ifndef CUB3D_H
#define CUB3D_H

#include <libft.h>
#include <fcntl.h>
#include <stdbool.h>

#define TEX_SIZE 64
#define WIN_WIDTH 1920
#define WIN_HEIGHT 980

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


void	info_init(t_info *info, char *path);
void	ray_direct(t_info info);

#endif
