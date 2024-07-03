/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rorate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:05:19 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 09:49:27 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_dir_x(t_player player, double rad)
{
	int	new_dir_x;

	new_dir_x = player.dir_x * cos(rad) - player.dir_y * sin(rad);
	return (new_dir_x);
}

int	new_dir_y(t_player player, double rad)
{
	int	new_dir_y;

	new_dir_y = player.dir_x * sin(rad) + player.dir_y * cos(rad);
	return (new_dir_y);
}

void	rotate_player(t_player *player, int keycode)
{
	int	x;
	int	y;

	x = player->dir_x;
	y = player->dir_y;
	if (keycode == ROTATE_RIGHT)
	{
		x = new_dir_x(*player, RAD_PI / 2);
		y = new_dir_y(*player, RAD_PI / 2);
	}
	else if (keycode == ROTATE_LEFT)
	{
		x = new_dir_x(*player, MINUS_RAD_PI / 2);
		y = new_dir_y(*player, MINUS_RAD_PI / 2);
	}
	player->dir_x = x;
	player->dir_y = y;
	printf("new dir_x, dir_y %d, %d\n", x, y);
}
