/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:56 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/19 15:50:00 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	ft_abs(int value)
{
	if (value < 0)
		return -value;
	return value;
}

/*
initialize rays(struct ray)
- x_cam -> where is camera(-1 <= x <= 1)
- x/y_dir -> direction of the ray(vector of ray)
- x/y_map -> current position of ray on map
- delta_dist_x/y -> inclease of ditance acheving grid line 
*/
void	init_ray_info(int x, t_ray *ray, t_player *player)
{
	initialize_data(ray);
	ray->cam_x = 2*x / (double)WINT_WIDTH - 1;
	ray->dir_x = player->dir_x + (player->cam_palne_x * ray->cam_x);
	ray->dir_y = player->dir_y + (player->cam_palne_y * ray->cam_x);
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	if(ray->dir_x == 0)
		ray->delta_dist_x = -1;
	else
		ray->delta_dist_x = ft_abs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = -1;
	else
		ray->delta_dist_y = ft_abs(1 / ray->dir_y);
}

int get_dir_x_step(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
		return (-1);
	}
	ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	return (1);
}

int get_dir_y_step(t_ray *ray, t_player *player)
{
	if (ray->dir_y < 0)
	{
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
		return (-1);
	}
	ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	return (1);
}

bool is_hitting_wall(t_ray *ray, t_node **map)
{
	if ('0' < map[ray->map_x][ray->map_y] && map[ray->map_x][ray->map_y] <= '9')
		return (true);
	return (false);
}

/*
dda algorithm
side_dist/x/y -> incleasing disitance from player's position to intger oordinate
(step_x/y) = incleasing unit for maps to cast ray;
hitwall = check ray hit the map wall
*/
void dda_algorithm(t_ray *ray, t_info *info)
{
	bool hit_wall;
	int step_x;
	int step_y;

	step_x = get_dir_x_step(ray, info->player);
	step_y = get_dir_y_step(ray, info->player);
	hit_wall = 0;
	while (hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += step_x;
			ray->axis = X_AXIS;
		}
		else if (ray->side_dist_x >= ray->side_dist_y)
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += step_y;
			ray->axis = Y_AXIS;
		}
		hi_wall = is_hitting_wall(info->map, ray);
	}
}

/*
wall_dist = inclease/decrease of ray
wall_x -> distance of player's postion from hitting point of ray 
line_hight -> texture7s hight
strat_y -> start point y of drawing texture
end_y -> end point y of drawing texture
*/
void	get_wall_dist(t_ray *ray, t_player *player)
{
	int wall_dist;

	if (ray->axis == X_AXIS)
	{
		wall_dist = ray->side_dist_x - ray->delta_dist_x;
		ray->wall_x = player->pos_y + wall_dist * ray->dir_y;
	}
	else
	{
		wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		ray->wall_x = player->pos_x + wall_dist * ray->dir_x; 
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->line_height = WIN_HEIGHT / wall_dist;
	ray->start_y = (-ray->line_height / 2) + (WIN_HEIGHT / 2);
	if (ray->start_y < 0)
		ray->start_y = 0;
	ray->end_y = (ray->line_height / 2) + (WIN_HEIGHT /2);
	if (WIN_HEIGHT <= ray->end_y)
		ray->end_y = WIN_WIDTH - 1;
}

int	decide_dir_tex(t_ray *ray, t_player *player)
{
	int	wall_tex;
	if (ray->aixs == Y_AXIS)
	{
		if (ray->map_y < player->pos_y)
			wall_tex = WEST_WALL;
		else
		wall_tex = EAST_WALL;
	}
	else if (ray->map_x < player->pos_x)
		wall_tex = NORTH_WALL;
	else
		wall_tex = SOUTH_WALL;
	return (wall_tex);
}


/* Struct Texture
index -> which directions of texture by wall_tex
x -> x coordinate of texture
step -> 
pos -> postion of texture
*/
void	set_tex_info(t_ray *ray, t_texinfo *texture)
{
	texture->index = decide_dir_tex(ray, info->player);
	texture->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->axis == X_AXIS && ray->dir_x < 0) || (ray->axis == Y_AXIS && ray->dir_y > 0))
		texture->x = TEX_SIZE - texture->x - 1;
	texture->step = 1.0 * TEX_SIZE / ray->line_height;
	teture->pos = (ray->start_y - WIN_HEIGHT / 2 + ray->line_height /2) * texture->step;
}

void	update_tex_info(t_ray *ray, t_info *info, int x)
{
	int y;
	int color;


	y = ray->start_y;
	while (y < ray->end_y)
	{
		info->texture->y = (int)info->texture->pos	& (TEX_SIZE - 1);
		info->texture->pos += info->texture->step;
		color = info->tex_list[info->texture->index][TEX_SIZE * info->texture->y + info->texture->x];
		//TODO: we have to get color
		if (ray->axis == Y_AXIS)
			color = (color >> 1) & 8355711;
		info->tex_pixels[y][x] = color;
		y++;
	}
}

void	initialize_ray(t_ray *ray)
{
	ray->cam_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->axis = 0;
	ray->wall_x = 0;
	ray->line_height = 0;
	ray->start_y = 0;
	ray->end_y = 0;
}

void	raycasting(t_info *info)
{
	int	x;
	t_ray ray;

	initialize_ray(&ray);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_info(x, &ray, info);
		dda_algorithm(&ray, info);
		get_wall_dist(ray, info->player);
		set_tex_info(ray, info->texture);
		update_tex_info(ray, info, x);
		x++;
	}
}
