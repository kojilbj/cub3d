/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:31 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 10:49:58 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static size_t	count_height(char **filedata)
{
	size_t	height;

	height = 0;
	while (filedata[height] != NULL)
		height++;
	return (height);
}

static size_t	count_width(char *filedata)
{
	size_t	width;

	width = 0;
	while (filedata[width] != '\0')
		width++;
	return (width);
}

static t_node	*new_line(char *strline, size_t y)
{
	size_t	width;
	size_t	i;
	t_node	*line;

	if (is_valid_line(strline) == false)
		return (NULL);
	width = count_width(strline);
	line = malloc(sizeof(t_node) * (width + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (strline[i] != '\0')
	{
		ft_bzero(&line[i], sizeof(t_node));
		line[i].x = i;
		line[i].y = y;
		line[i].type = strline[i];
		i++;
	}
	ft_bzero(&line[i], sizeof(t_node));
	return (line);
}

static t_node	**map_alloc(char **filedata)
{
	size_t	start;
	size_t	i;
	size_t	height;
	t_node	**map;

	start = 6;
	i = 0;
	height = count_height(&filedata[start]);
	map = malloc(sizeof(t_node *) * (height + 1));
	if (map == NULL)
		return (NULL);
	map[height] = NULL;
	while (i < height)
	{
		map[i] = new_line(filedata[start + i], i);
		if (map[i] == NULL)
		{
			free_all((void **)map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	map_init(t_info *info, char **filedata)
{
	t_node	**map;

	map = map_alloc(filedata);
	if (map == NULL)
		return (1);
	if (is_valid_map(map) == false)
	{
		free_all((void *)map);
		free(map);
		map = NULL;
	}
	info->map = map;
	if (map == NULL)
		return (1);
	return (0);
}
