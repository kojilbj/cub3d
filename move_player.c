/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:05:19 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/10 13:20:08 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	cast_dir(double dir)
{
	if (fabs(dir) > 0.5 && dir > 0)
		dir = 1;
	else if (fabs(dir) > 0.5 && dir < 0)
		dir = -1;
	else
		dir = 0;
	return (dir);
}

int	new_pos_x(t_player player, int keycode)
{
	int	x;
	int	dir_x;

	x = player.pos_x;
	dir_x = cast_dir(player.dir_x);
	if (keycode == FORWARD)
		x = player.pos_x + dir_x;
	if (keycode == BACK)
		x = player.pos_x - dir_x;
	if (keycode == RIGHT)
		x = player.pos_x + cast_dir(new_dir_x(player, RAD_PI / 2));
	if (keycode == LEFT)
		x = player.pos_x + cast_dir(new_dir_x(player, MINUS_RAD_PI / 2));
	return (x);
}

int	new_pos_y(t_player player, int keycode)
{
	int	y;
	int	dir_y;

	y = player.pos_y;
	dir_y = cast_dir(player.dir_y);
	if (keycode == FORWARD)
		y = player.pos_y + dir_y;
	if (keycode == BACK)
		y = player.pos_y - dir_y;
	if (keycode == RIGHT)
		y = player.pos_y + cast_dir(new_dir_y(player, RAD_PI / 2));
	if (keycode == LEFT)
		y = player.pos_y + cast_dir(new_dir_y(player, MINUS_RAD_PI / 2));
	return (y);
}

int	move_player_check(t_node **map, int x, int y)
{
	if (map[y][x].type == '1')
		return (false);
	else
		return (true);
}

void	move_player(t_vars *vars, int keycode)
{
	int	pos_x;
	int	pos_y;
	int	last_pos_x;
	int	last_pos_y;

	last_pos_x = vars->info.player.pos_x;
	last_pos_y = vars->info.player.pos_y;
	pos_x = new_pos_x(vars->info.player, keycode);
	pos_y = new_pos_y(vars->info.player, keycode);
	if (move_player_check(vars->info.map, pos_x, pos_y) == true)
	{
		vars->info.map[last_pos_y][last_pos_x].type = '0';
		vars->info.player.pos_x = pos_x;
		vars->info.player.pos_y = pos_y;
		vars->info.map[pos_y][pos_x].type = 'P';
	}
}
