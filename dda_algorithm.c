/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:16:34 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/21 00:16:36 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_dir_x_step(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
		return (-1);
	}
	ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	return (1);
}

static int get_dir_y_step(t_ray *ray, t_player *player)
{
	if (ray->dir_y < 0)
	{
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
		return (-1);
	}
	ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	return (1);
}

static bool is_hitting_wall(t_ray *ray, t_node **map)
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
