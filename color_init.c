#include "./cub3d.h"

static int	floor_color_init(char **floor_rgb, char **sp)
{
	if (perfectly_match(sp[0], "F"))
	{
		if (*floor_rgb != NULL)
			return (1);
		*floor_rgb = ft_strdup(sp[1]);
	}
	return (0);
}

static int	ceiling_color_init(char **ceiling_rgb, char **sp)
{
	if (perfectly_match(sp[0], "C"))
	{
		if (*ceiling_rgb != NULL)
			return (1);
		*ceiling_rgb = ft_strdup(sp[1]);
	}
	return (0);
}

int	color_init(t_info *info, char **filedata)
{
	size_t	i;
	int	ret;
	char	**splited;

	i = 0;
	ret = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		ret |= floor_color_init(&(info->floor_rgb), splited);
		ret |= ceiling_color_init(&(info->ceiling_rgb), splited);
		free(splited[0]);
		free(splited[1]);
		i++;
	}
	return (ret);
}