#include "./cub3d.h"

static bool	is_valid_format(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && str[i] !=  ' ' && ft_isdigit(str[i]) != 1)
		{
			ft_putstr_fd("Error\nInvalid color format.\n", STDERR_FILENO);
			return (false);
		}
		i++;
	}
	return (true);
}

static int	color_range_check(char *str)
{
	char	**sp;
	int	num;
	int	ret;
	size_t	i;

	sp = ft_split(str, ',');
	i = 0;
	ret = 0;
	while (sp[i] != NULL)
	{
		num = ft_atoi(sp[i]);
		if (!(0 <= num && num < 256))
			ret = 1;	
		free(sp[i]);
		i++;
	}
	free(sp);
	return (ret);
}

static int	floor_color_init(char **floor_rgb, char **sp)
{
	char	*str;

	if (perfectly_match(sp[0], "F"))
	{
		if (*floor_rgb != NULL)
		{
			ft_putstr_fd("Error\nFloor color is duplicated\n", 	STDERR_FILENO);
			return (1);
		}
		if (is_valid_format(sp[1]) == true && color_range_check(sp[1]) == 0)
			*floor_rgb = ft_strdup(sp[1]);
		else
		{
			ft_putstr_fd("Error\nInvalid RGB range.\n", 	STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}

static int	ceiling_color_init(char **ceiling_rgb, char **sp)
{
	if (perfectly_match(sp[0], "C"))
	{
		if (*ceiling_rgb != NULL)
		{
			ft_putstr_fd("Error\nCeiling color is duplicated\n", 	STDERR_FILENO);
			return (1);
		}
		if (is_valid_format(sp[1]) == true && color_range_check(sp[1]) == 0)
			*ceiling_rgb = ft_strdup(sp[1]);
		else
		{
			ft_putstr_fd("Error\nInvalid RGB range.\n", 	STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}

static int color_init_check(t_info info)
{
	int	ret;

	ret = 0;
	ret |= info.floor_rgb == NULL;
	ret |= info.ceiling_rgb == NULL;
	if (ret != 0)
		ft_putstr_fd("Error\nFloor or(and) Ceiling color does not exist\n", STDERR_FILENO);
	return (ret);
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
	ret |= color_init_check(*info);
	return (ret);
}