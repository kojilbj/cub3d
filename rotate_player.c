/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:05:19 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/10 21:02:15 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	new_dir_x(t_player player, double rad)
{
	double	new_dir_x;

	new_dir_x = player.dir_x * cos(rad) - player.dir_y * sin(rad);
	return (new_dir_x);
}

double	new_dir_y(t_player player, double rad)
{
	double	new_dir_y;

	new_dir_y = player.dir_x * sin(rad) + player.dir_y * cos(rad);
	return (new_dir_y);
}

void	rotate_player(t_player *player, int keycode, int count)
{
	double	x;
	double	y;

	x = player->dir_x;
	y = player->dir_y;
	if (keycode == ROTATE_RIGHT)
	{
		x = new_dir_x(*player, RAD_PI / (2 * count));
		y = new_dir_y(*player, RAD_PI / (2 * count));
	}
	else if (keycode == ROTATE_LEFT)
	{
		x = new_dir_x(*player, MINUS_RAD_PI / (2 * count));
		y = new_dir_y(*player, MINUS_RAD_PI / (2 * count));
	}
	player->dir_x = x;
	player->dir_y = y;
}

void	rotate_camera(t_vars *vars, int keycode)
{
	int	count;
	int	i;

	count = 5;
	i = 0;
	while (i < count)
	{
		rotate_player(&(vars->info.player), keycode, count);
		rendering(vars);
		double_free(vars->info.tex_pixels);
		i++;
	}
}
