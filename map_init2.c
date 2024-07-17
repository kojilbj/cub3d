/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:31 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/17 18:58:37 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static bool	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != ' ' && is_player(c) == false)
		return (false);
	return (true);
}

bool	is_valid_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (is_valid_char(line[i]) == false)
		{
			put_error("Invalid charcter in map.\n");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_valid_location(t_node **map, int x, int y)
{
	if (is_boader_of_map(map, x, y) == true)
	{
		put_error("Invalid map.\n");
		return (false);
	}
	if (is_next_to_blank(map, x, y) == true)
	{
		put_error("Invalid map.\n");
		return (false);
	}
	if (exist_updown(map, x, y) == false)
	{
		put_error("Invalid map.\n");
		return (false);
	}
	return (true);
}

bool	is_valid_map(t_node **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x].type != '\0')
		{
			if (map[y][x].type != '1' && map[y][x].type != ' ')
			{
				if (is_valid_location(map, x, y) == false)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
