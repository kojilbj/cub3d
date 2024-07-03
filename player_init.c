/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:28 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 11:00:44 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	else
		return (false);
}

static int	dir_init(t_player *player, char c)
{
	if (player->dir_x != 0 && player->dir_y != 0)
		return (1);
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	return (0);
}

static int	pos_init(t_player *player, int x, int y)
{
	player->pos_x = x;
	player->pos_y = y;
	return (0);
}

static int	player_init_check(t_player player)
{
	int	val;

	val = 0;
	val |= player.dir_x != 0;
	val |= player.dir_y != 0;
	val |= player.pos_x != 0;
	val |= player.pos_y != 0;
	if (val != 0)
		return (0);
	else
		return (1);
}

int	player_init(t_info *info, char **filedata)
{
	size_t	x;
	size_t	y;
	int		ret;
	char	**map;

	map = &filedata[6];
	x = 0;
	y = 0;
	ret = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (is_player(map[y][x]) == true)
				ret |= dir_init(&(info->player), map[y][x]);
			if (is_player(map[y][x]) == true)
				ret |= pos_init(&(info->player), x, y);
			x++;
		}
		y++;
	}
	if (ret != 0 || player_init_check(info->player))
		put_error("player.");
	return (ret || player_init_check(info->player));
}
