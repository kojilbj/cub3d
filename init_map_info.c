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

void	init_map_info(t_info *info, char *path)
{
	int	fd;
	char	*filedata;
	char	**splited;

	ft_bzero(info, sizeof(t_info));
	filedata = file_to_string(path);
	if (filedata == NULL)
		return ;
	splited = ft_split(filedata, '\n');
	texture_init(info, splited);
	color_init(info, splited);
	player_init(info, splited);
	map_init(info, splited);
	free_all((void **)splited);
	free(splited);
}
