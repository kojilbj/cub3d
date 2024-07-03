/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:31 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 10:53:51 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

bool	is_boader_of_map(t_node **map, int x, int y)
{
	if (y == 0 || x == 0)
		return (true);
	if (map[y][x + 1].type == '\0')
		return (true);
	if (map[y + 1] == NULL)
		return (true);
	return (false);
}

bool	is_next_to_blank(t_node **map, int x, int y)
{
	if (map[y + 1][x].type == ' ')
		return (true);
	if (map[y - 1][x].type == ' ')
		return (true);
	if (map[y][x + 1].type == ' ')
		return (true);
	if (map[y][x - 1].type == ' ')
		return (true);
	return (false);
}
