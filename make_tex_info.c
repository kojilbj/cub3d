/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tex_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:26:12 by hosonu            #+#    #+#             */
/*   Updated: 2024/07/17 18:33:53 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Struct Texture
index -> which directions of texture by wall_tex
x -> x coordinate of texture
step -> 
pos -> postion of texture
*/
static int	decide_dir_tex(t_ray *ray, t_player player)
{
	int	wall_tex;

	if (ray->axis == Y_AXIS)
	{
		if (ray->map_y < player.pos_y)
			wall_tex = SOUTH_WALL;
		else
			wall_tex = NORTH_WALL;
	}
	else if (ray->map_x < player.pos_x)
		wall_tex = WEST_WALL;
	else
		wall_tex = EAST_WALL;
	return (wall_tex);
}

void	set_tex_info(t_ray *ray, t_texinfo *texture, t_player player)
{
	texture->index = decide_dir_tex(ray, player);
	texture->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->axis == X_AXIS && ray->dir_x < 0)
		|| (ray->axis == Y_AXIS && ray->dir_y > 0))
		texture->x = TEX_SIZE - texture->x - 1;
	texture->step = (1.0 * TEX_SIZE) / ray->line_height;
	texture->pos = (ray->start_y - (WIN_HEIGHT / 2)
			+ ray->line_height / 2) * texture->step;
}

void	update_tex_info(t_ray *ray, t_info *info, int x)
{
	int	y;
	int	color;

	y = ray->start_y;
	while (y < ray->end_y)
	{
		info->texture.y = (int)info->texture.pos & (TEX_SIZE - 1);
		info->texture.pos += info->texture.step;
		color = info->tex_list[info->texture.index]
		[(TEX_SIZE * info->texture.y) + info->texture.x];
		if (ray->axis == Y_AXIS)
			color = (color >> 1) & 8355711;
		info->tex_pixels[y][x] = color;
		y++;
	}
}
