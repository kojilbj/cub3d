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
		if (map[i] ==  NULL)
		{
			free_all(map);
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
	info->map = map;
	if (map == NULL)
		return (1);
}
