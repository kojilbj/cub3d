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
void	init_ray_info(int x, t_ray *ray, t_player player)
{
	ray->cam_x = 2*x / (double)WIN_WIDTH - 1;
	ray->dir_x = player.dir_x + (player.cam_palne_x * ray->cam_x);
	ray->dir_y = player.dir_y + (player.cam_palne_y * ray->cam_x);
	ray->map_x = player.pos_x;
	ray->map_y = player.pos_y;
	if(ray->dir_x == 0)
		ray->delta_dist_x = -1;
	else
		ray->delta_dist_x = ft_abs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = -1;
	else
		ray->delta_dist_y = ft_abs(1 / ray->dir_y);
}
/*
wall_dist = inclease/decrease of ray
wall_x -> distance of player's postion from hitting point of ray 
line_hight -> texture7s hight
strat_y -> start point y of drawing texture
end_y -> end point y of drawing texture
*/
static void	get_wall_dist(t_ray *ray, t_player player)
{
	int wall_dist;

	if (ray->axis == X_AXIS)
	{
		wall_dist = ray->side_dist_x - ray->delta_dist_x;
		ray->wall_x = player.pos_y + wall_dist * ray->dir_y;
	}
	else
	{
		wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		ray->wall_x = player.pos_x + wall_dist * ray->dir_x; 
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

void	raycasting(t_info *info)
{
	int	x;
	t_ray ray;

	ft_bzero(&ray, sizeof(ray));// initialize_ray(&ray);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_info(x, &ray, info->player);
		dda_algorithm(&ray, info);
		get_wall_dist(&ray, info->player);
		set_tex_info(&ray, info->texture, info->player);
		update_tex_info(&ray, info, x);
		x++;
	}
}

// void	initialize_ray(t_ray *ray)
// {
// 	ray->cam_x = 0;
// 	ray->dir_x = 0;
// 	ray->dir_y = 0;
// 	ray->map_x = 0;
// 	ray->map_y = 0;
// 	ray->side_dist_x = 0;
// 	ray->side_dist_y = 0;
// 	ray->delta_dist_x = 0;
// 	ray->delta_dist_y = 0;
// 	ray->axis = 0;
// 	ray->wall_x = 0;
// 	ray->line_height = 0;
// 	ray->start_y = 0;
// 	ray->end_y = 0;
// }