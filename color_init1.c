/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:36 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 12:25:19 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static int	floor_color_init(char **floor_rgb, char **sp)
{
	if (perfectly_match(sp[0], "F"))
	{
		if (*floor_rgb != NULL)
		{
			put_error("Floor color is duplicated\n");
			return (1);
		}
		if (is_valid_format(sp[1]) == true && color_range_check(sp[1]) == 0)
			*floor_rgb = ft_strdup(sp[1]);
		else
		{
			put_error("Invalid RGB range.\n");
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
			put_error("Ceiling color is duplicated\n");
			return (1);
		}
		if (is_valid_format(sp[1]) == true && color_range_check(sp[1]) == 0)
			*ceiling_rgb = ft_strdup(sp[1]);
		else
		{
			put_error("Invalid RGB range.\n");
			return (1);
		}
	}
	return (0);
}

static int	color_init_check(t_info info)
{
	int	ret;

	ret = 0;
	ret |= info.floor_rgb == NULL;
	ret |= info.ceiling_rgb == NULL;
	if (ret != 0)
		put_error("Floor or(and) Ceiling color does not exist\n");
	return (ret);
}

int	color_init(t_info *info, char **filedata)
{
	size_t	i;
	int		ret;
	char	**splited;

	i = 0;
	ret = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		ret |= floor_color_init(&(info->floor_rgb), splited);
		ret |= ceiling_color_init(&(info->ceiling_rgb), splited);
		free_all((void **)splited);
		free(splited);
		i++;
	}
	ret |= color_init_check(*info);
	return (ret);
}
