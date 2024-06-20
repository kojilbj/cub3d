#include "cub3d.h"

int	perfectly_match(char *s1, char *s2)
{
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (false);
	ret = ft_strnstr(s1, s2, ft_strlen(s1));
	if (ret == NULL)
		return (false);
	ret = ft_strnstr(s2, s1, ft_strlen(s2));
	if (ret == NULL)
		return (false);
	return (true);
}

char	*file_data_str(char *path)
{
	int		fd;
	char	buff[1024];
	char	*data;
	int		ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (NULL);
	}
	ret = read(fd, buff, 1);
	if (ret < 0)
		return (NULL);
	buff[ret] = '\0';
	data = ft_strjoin(NULL, buff);
	while (ret == 1)
	{
		ret = read(fd, buff, sizeof(buff) - 1);
		buff[ret] = '\0';
		data = ft_strjoin(data, buff);
	}
	close(fd);
	return (data);
}

void	texture_init(t_info *info, char **filedata)
{
	size_t	i;
	char	**splited;

	i = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		if (perfectly_match(splited[0], "NO"))
		{
			if (info->tex_no != NULL)
				exit(EXIT_FAILURE);
			info->tex_no = ft_strdup(splited[1]);
		}
		else if (perfectly_match(splited[0], "SO"))
		{
			if (info->tex_so != NULL)
				exit(EXIT_FAILURE);
			info->tex_so = ft_strdup(splited[1]);
		}
		else if (perfectly_match(splited[0], "WE"))
		{
			if (info->tex_we != NULL)
				exit(EXIT_FAILURE);
			info->tex_we = ft_strdup(splited[1]);
		}
		else if (perfectly_match(splited[0], "EA"))
		{
			if (info->tex_ea != NULL)
				exit(EXIT_FAILURE);
			info->tex_ea = ft_strdup(splited[1]);
		}
		free(splited[0]);
		free(splited[1]);
		i++;
	}
}

void	color_init(t_info *info, char **filedata)
{
	size_t	i;
	char	**splited;

	i = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		if (perfectly_match(splited[0], "F"))
		{
			if (info->floor_rgb != NULL)
				exit(EXIT_FAILURE);
			info->floor_rgb = ft_strdup(splited[1]);
		}
		if (perfectly_match(splited[0], "C"))
		{
			if (info->ceiling_rgb != NULL)
				exit(EXIT_FAILURE);
			info->ceiling_rgb = ft_strdup(splited[1]);
		}
		free(splited[0]);
		free(splited[1]);
		i++;
	}
}

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

t_node	*new_line(char *strline, size_t y)
{
	size_t	width;
	size_t	i;
	t_node	*line;

	width = count_width(strline);
	line = malloc(sizeof(t_node) * (width + 1));
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

t_node	**map_alloc(char **filedata)
{
	size_t	start;
	size_t	i;
	size_t	height;
	t_node	**map;

	start = 6;
	i = 0;
	height = count_height(&filedata[start]);
	map = malloc(sizeof(t_node *) * (height + 1));
	map[height] = NULL;
	while (i < height)
	{
		map[i] = new_line(filedata[start + i], i);
		i++;
	}
	return (map);
}

void	map_init(t_info *info, char **filedata)
{
	t_node	**map;

	map = map_alloc(filedata);
	info->map = map;
}

void	free_all(char **data)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
}

int	is_player(char c)
{
	if (c != '0' && c != '1' && c != ' ')
		return (true);
	else
		return (false);
}

void	player_init(t_info *info)
{
	size_t	x;
	size_t	y;
	t_node	**map;

	x = 0;
	y = 0;
	map = info->map;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x].type != 0)
		{
			if (map[y][x].type == 'N')
			{
				info->player.dir_x = 0;
				info->player.dir_y = -1;
			}
			if (map[y][x].type == 'E')
			{
				info->player.dir_x = 1;
				info->player.dir_y = 0;
			}
			if (map[y][x].type == 'S')
			{
				info->player.dir_x = 0;
				info->player.dir_y = 1;
			}
			if (map[y][x].type == 'W')
			{
				info->player.dir_x = -1;
				info->player.dir_y = 0;
			}
			if (is_player(map[y][x].type) == true)
			{
				info->player.pos_x = x;
				info->player.pos_y = y;
				map[y][x].type = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	info_init(t_info *info, char *path)
{
	char	*filedata;
	char	**splited;

	ft_bzero(info, sizeof(t_info));
	filedata = file_data_str(path);
	if (filedata == NULL)
		return ;
	splited = ft_split(filedata, '\n');
	texture_init(info, splited);
	color_init(info, splited);
	map_init(info, splited);
	player_init(info);
	free_all(splited);
	free(splited);
}
