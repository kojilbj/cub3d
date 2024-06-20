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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	cam_palne_x;
	double	cam_palne_y;
}	t_player;

typedef struct s_ray
{
	double cam_x;
	double dir_x;
	double dir_y;
	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	int axis;
	double wall_x;
	int	line_height;
	int start_y;
	int end_y;
} t_ray;

typedef struct s_texinfo
{
	int x;
	int y;
	double step;
	double pos;
	int index;
	
} t_texinfo;

typedef struct	s_info
{
	t_node	**map;
	t_player	player;
	t_texinfo *texture;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	*floor_rgb;
	char	*ceiling_rgb;

	int		**tex_list;//TODO: make & init this texture list
	int		**tex_pixels;//
}	t_info;

void	info_init(t_info *info, char *path);
void	ray_direct(t_info info);

#endif
