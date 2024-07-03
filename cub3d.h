/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:56 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 11:45:25 by watanabekoj      ###   ########.fr       */
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

# define TEX_SIZE 64
# define WIN_WIDTH 720
# define WIN_HEIGHT 360

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

typedef struct s_node
{
	int		x;
	int		y;
	int		distance;
	char	type;
}	t_node;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;
}	t_player;

typedef struct s_info
{
	t_node		**map;
	t_player	player;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	char		*floor_rgb;
	char		*ceiling_rgb;
}	t_info;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_info	info;
}	t_vars;

//-----------------------
//			init_map_info.c
//-----------------------
int		init_map_info(t_info *info, char *path);
int		perfectly_match(char *s1, char *s2);

//-----------------------
//			color_init1.c
//-----------------------
int		color_init(t_info *info, char **filedata);

//-----------------------
//			color_init2.c
//-----------------------
int		color_range_check(char *str);
bool	is_valid_format(char *str);

//-----------------------
//			texture_init1.c
//-----------------------
int		texture_init(t_info *info, char **filedata);

//-----------------------
//			texture_init2.c
//-----------------------
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
//			map_init1.c
//-----------------------
int		map_init(t_info *info, char **filedata);

//-----------------------
//			map_init2.c
//-----------------------
bool	is_valid_map(t_node **map);
bool	is_valid_line(char *line);

//-----------------------
//			map_init3.c
//-----------------------
bool	is_boader_of_map(t_node **map, int x, int y);
bool	is_next_to_blank(t_node **map, int x, int y);

//-----------------------
//			rotate_player.c
//-----------------------
void	rotate_player(t_player *player, int keycode);
int		new_dir_x(t_player player, double rad);
int		new_dir_y(t_player player, double rad);

//-----------------------
//			  move_player.c
//-----------------------
void	move_player(t_vars *vars, int keycode);
int		new_pos_x(t_player player, int keycode);
int		new_pos_y(t_player player, int keycode);

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

#endif
