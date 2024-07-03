/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:05:19 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 09:51:27 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_pos_x(t_player player, int keycode)
{
	int	x;

	x = player.pos_x;
	if (keycode == FORWARD)
		x = player.pos_x + player.dir_x;
	if (keycode == BACK)
		x = player.pos_x - player.dir_x;
	if (keycode == RIGHT)
		x = player.pos_x + new_dir_x(player, RAD_PI / 2);
	if (keycode == LEFT)
		x = player.pos_x + new_dir_x(player, MINUS_RAD_PI / 2);
	return (x);
}

int	new_pos_y(t_player player, int keycode)
{
	int	y;

	y = player.pos_y;
	if (keycode == FORWARD)
		y = player.pos_y + player.dir_y;
	if (keycode == BACK)
		y = player.pos_y - player.dir_y;
	if (keycode == RIGHT)
		y = player.pos_y + new_dir_y(player, RAD_PI / 2);
	if (keycode == LEFT)
		y = player.pos_y + new_dir_y(player, MINUS_RAD_PI / 2);
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
	printf("last %d, %d\n", last_pos_x, last_pos_y);
	pos_x = new_pos_x(vars->info.player, keycode);
	pos_y = new_pos_y(vars->info.player, keycode);
	if (move_player_check(vars->info.map, pos_x, pos_y) == true)
	{
		printf("new %d, %d\n", pos_x, pos_y);
		vars->info.map[last_pos_y][last_pos_x].type = '0';
		vars->info.player.pos_x = pos_x;
		vars->info.player.pos_y = pos_y;
		vars->info.map[pos_y][pos_x].type = 'P';
	}
}
