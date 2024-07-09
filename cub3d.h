/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:56 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/09 23:41:52 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

//--------------------
//				WINDOW
//--------------------
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720 

// 180 * M_PI / 180 = RAD_PI
# define RAD_PI 3.14159265358979323846
// -180 * M_PI / 180 = MINUS_RAD_PI
# define MINUS_RAD_PI -3.14159265358979323846

# define ESC 65307
# define ROTATE_RIGHT 65363
# define ROTATE_LEFT 65361
# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97

//--------------------
//			RAYCASTING
//--------------------
# define X_AXIS 0
# define Y_AXIS 1

//---------------------
//				TEXTURE
//---------------------
# define TEX_SIZE 64
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

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bites_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

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
}	t_ray;

typedef struct s_texinfo
{
	int		x;
	int		y;
	double	step;
	double	pos;
	int		index;
}	t_texinfo;

typedef struct s_node
{
	int		x;
	int		y;
	int		distance;
	char	type;
}	t_node;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	float	dir_x;
	float	dir_y;
}	t_player;

typedef struct s_info
{
	t_node		**map;
	t_player	player;
	t_texinfo	texture;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			floor_rgb;
	int			ceiling_rgb;

	int			**tex_list;
	int			**tex_pixels;
}	t_info;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_info	info;
}	t_vars;

//-------------------------------//
			/*FUNCTIONS*/			
//------------------------------//

//-----------------------
//			init_map_info.c
//-----------------------
int		init_map_info(t_info *info, char *path);
int		perfectly_match(char *s1, char *s2);

//-----------------------
//			color_init*.c
//-----------------------
int		color_init(t_info *info, char **filedata);

int		color_range_check(char *str);
bool	is_valid_format(char *str);
int		convert_str_to_rgb(char *str);

//-----------------------
//			texture_init*.c
//-----------------------
int		texture_init(t_info *info, char **filedata);

int		north_tex_init(char **tex_no, char **sp);
int		south_tex_init(char **tex_so, char **sp);
int		east_tex_init(char **tex_ea, char **sp);
int		west_tex_init(char **tex_we, char **sp);

//-----------------------
//			player_init.c
//-----------------------
int		player_init(t_info *info, char **filedata);
bool	is_player(char c);

//-----------------------
//			map_init*.c
//-----------------------
int		map_init(t_info *info, char **filedata);

bool	is_valid_map(t_node **map);
bool	is_valid_line(char *line);

bool	is_boader_of_map(t_node **map, int x, int y);
bool	is_next_to_blank(t_node **map, int x, int y);

//-----------------------
//			rotate_player.c
//-----------------------
void	rotate_camera(t_vars *vars, int keycode);
void	rotate_player(t_player *player, int keycode, int count);
float	new_dir_x(t_player player, double rad);
float	new_dir_y(t_player player, double rad);

//-----------------------
//			  move_player.c
//-----------------------
void	move_player(t_vars *vars, int keycode);
int		new_pos_x(t_player player, int keycode);
int		new_pos_y(t_player player, int keycode);

//-----------------------
//  initialize_tex_list.c
//-----------------------
void	initialize_tex_list(t_vars *vars);

//-----------------------
//			  rendering.c
//-----------------------
void	rendering(t_vars *vars);
int		render(t_vars *vars);

//-----------------------
//			 raycasting.c
//-----------------------
void	raycasting(t_info *info);

//dda_algorithm.c -> raycasitng.c
//------------------------
void	dda_algorithm(t_ray *ray, t_info *info);

//make_tex_info.c -> raycasitng.c
//------------------------
void	set_tex_info(t_ray *ray, t_texinfo *texture, t_player player);
void	update_tex_info(t_ray *ray, t_info *info, int x);

//-----------------------
//			validate.c
//-----------------------
void	put_error(char *errmsg);
int		file_name_validate(char *arg);

//-----------------------
//			file_to_string.c
//-----------------------
char	*file_to_string(char *path);

//-----------------------
//			custom_free.c
//-----------------------
void	free_all(void **data);
void	free_info(t_info info);

//-----------------------
//			x_func.c
//-----------------------
int		x_open(char *path, int oflag);
void	double_free(int **tab);

#endif
