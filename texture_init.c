#include "./cub3d.h"

static int	north_tex_init(char **tex_no, char **sp)
{
	if (perfectly_match(sp[0], "NO"))
	{
		if (*tex_no != NULL)
		{
			ft_putstr_fd("Error\nnorth texture is duplicated.\n", STDERR_FILENO);
			return (1);
		}
		*tex_no = ft_strdup(sp[1]);
	}
	return (0);
}

static int	south_tex_init(char **tex_so, char **sp)
{
	if (perfectly_match(sp[0], "SO"))
	{
		if (*tex_so != NULL)
		{
			ft_putstr_fd("Error\nsouth texture is duplicated.\n", STDERR_FILENO);
			return (1);
		}
		*tex_so = ft_strdup(sp[1]);
	}
	return (0);
}

static int	east_tex_init(char **tex_ea, char **sp)
{
	if (perfectly_match(sp[0], "EA"))
	{
		if (*tex_ea != NULL)
		{
			ft_putstr_fd("Error\neast texture is duplicated.\n", STDERR_FILENO);
			return (1);
		}
		*tex_ea = ft_strdup(sp[1]);
	}
	return (0);
}

static int	west_tex_init(char **tex_we, char **sp)
{
	if (perfectly_match(sp[0], "WE"))
	{
		if (*tex_we != NULL)
		{
			ft_putstr_fd("Error\nwest texture is duplicated.\n", STDERR_FILENO);
			return (1);
		}
		*tex_we = ft_strdup(sp[1]);
	}
	return (0);
}

int	texture_init(t_info *info, char **filedata)
{
	size_t	i;
	char	**splited;
	int	ret;

	i = 0;
	ret = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		if (splited == NULL)
			return 1; 
		// return value should be caluculated with bit operations. like ret | tex_*_init
		ret |= north_tex_init(&(info->tex_no), splited);
		ret |= south_tex_init(&(info->tex_so), splited);
		ret |= east_tex_init(&(info->tex_ea), splited);
		ret |= west_tex_init(&(info->tex_we), splited);
		free(splited[0]);
		free(splited[1]);
		i++;
	}
	return (ret);
}