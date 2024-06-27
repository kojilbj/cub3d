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

bool	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != ' ' && is_player(c) == false)
		return (false);
	return (true);
}

static bool	is_valid_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (is_valid_char(line[i]) == false)
		{
			ft_putstr_fd("Error\nInvalid charcter in map.\n", STDERR_FILENO);
			return (false);
		}
		i++;
	}
	return (true);
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
		if (map[i] ==  NULL)
		{
			free_all((void **)map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static	bool	is_boader_of_map(t_node **map, int x, int y)
{
	if (y == 0 || x == 0)
		return (true);
	if (map[y][x + 1].type == '\0')
		return (true);
	if (map[y + 1] == NULL)
		return (true);
	return (false);
}

static bool	is_next_to_blank(t_node **map, int x, int y)
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

static bool	is_valid_location(t_node **map, int x, int y)
{
	if (is_boader_of_map(map, x, y) == true)
	{
		ft_putstr_fd("Error\nInvalid map.\n", STDERR_FILENO);
		return (false);
	}
	if (is_next_to_blank(map, x, y) == true)
	{
		ft_putstr_fd("Error\nInvalid map.\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

static bool	is_valid_map(t_node **map)
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
