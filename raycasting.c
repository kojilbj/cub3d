/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:56 by hosonu            #+#    #+#             */
/*   Updated: 2024/07/03 23:23:40 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
initialize rays(struct ray)
- x_cam -> where is camera(-1 <= x <= 1)
- x/y_dir -> direction of the ray(vector of ray)
- x/y_map -> current position of ray on map
- delta_dist_x/y -> inclease of ditance acheving grid line 
*/

void	init_ray_info(int x, t_ray *ray, t_player player)
{
	ray->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player.dir_x + -player.dir_y * 0.66 * ray->cam_x;
	ray->dir_y = player.dir_y + player.dir_x * 0.66 * ray->cam_x;
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
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
	double wall_dist;

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
	ray->line_height = (int)(WIN_HEIGHT / wall_dist);
	ray->start_y = -(ray->line_height) / 2 + (WIN_HEIGHT / 2);
	if (ray->start_y < 0)
		ray->start_y = 0;
	ray->end_y = ray->line_height / 2 + (WIN_HEIGHT / 2);
	if (ray->end_y >= WIN_HEIGHT)
		ray->end_y = WIN_HEIGHT - 1;
}

void	raycasting(t_info *info)
{
	int	x;
	t_ray ray;

	ft_bzero(&ray, sizeof(ray));
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_info(x, &ray, info->player);
		dda_algorithm(&ray, info);
		get_wall_dist(&ray, info->player);
		set_tex_info(&ray, &(info->texture), info->player);
		update_tex_info(&ray, info, x);
		x++;
	}
}
