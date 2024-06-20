#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//--------------------
//				WINDOW
//--------------------
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

//--------------------
//			RAYCASTING
//--------------------

# define X_AXIS 0
# define Y_AXIS 1

//---------------------
//				TEXTURE
//---------------------
#define TEX_SIZE 64
# define SOUTH_WALL 0
# define NORTH_WALL 1
# define EAST_WALL 2 
# define WEST_WALL 3

enum e_tex_list_index
{
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
};


//-------------------------------//
			/*STRUCTURES*/			
//------------------------------//

typedef struct	s_node
{
	int		x;
	int		y;
	char	type;
	int		distance;
}	t_node;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bites_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

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
	double	cam_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		axis;
	double	wall_x;
	int		line_height;
	int		start_y;
	int		end_y;
} t_ray;

typedef struct s_texinfo
{
	int		x;
	int		y;
	double	step;
	double	pos;
	int		index;
	
} t_texinfo;

typedef struct	s_info
{
	t_node		**map;
	t_player	player;
	t_texinfo	*texture;

	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	char		*floor_rgb;
	char		*ceiling_rgb;

	int			**tex_list;
	int			**tex_pixels;
}	t_info;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_info	info;
}	t_vars;

//-------------------------------//
			/*FUNCTIONS*/			
//------------------------------//

void	info_init(t_info *info, char *path);
void	info_init(t_info *info, char *path);
void	rotate_player(t_player *player, int keycode);
void	move_player(t_vars *vars, int keycode);
int		new_dir_x(t_player player, double rad);
int		new_dir_y(t_player player, double rad);
int		new_pos_x(t_player player, int keycode);
int		new_pos_y(t_player player, int keycode);

void	err_terminate(char *errmsg);
int		validate(t_info info);


// void	initialize_tex_list(t_info *info);
void	initialize_tex_list(t_vars *vars);

void	rendering(t_vars *vars);

//-----------------------
//			 raycasting.c
//-----------------------
void	raycasting(t_info *info);

//-----------------------
//    	  dda_algorithm.c -> raycasitng.c
//-----------------------
void	dda_algorithm(t_ray *ray, t_info *info);

//------------------------
//		   make_tex_info.c  -> raycasitng.c
//------------------------
void	set_tex_info(t_ray *ray, t_texinfo *texture, t_player player);
void	update_tex_info(t_ray *ray, t_info *info, int x);

#endif
