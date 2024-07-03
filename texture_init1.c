/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:49 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 12:25:42 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static int	texture_init_check(t_info info)
{
	int	ret;

	ret = 0;
	ret += info.tex_no == NULL;
	ret += info.tex_so == NULL;
	ret += info.tex_ea == NULL;
	ret += info.tex_we == NULL;
	if (ret != 0)
		put_error("Texture info is not enough");
	return (ret);
}

int	texture_init(t_info *info, char **filedata)
{
	size_t	i;
	char	**splited;
	int		ret;

	i = 0;
	ret = 0;
	while (filedata[i] != NULL)
	{
		splited = ft_split(filedata[i], ' ');
		if (splited == NULL)
			return (1);
		ret |= north_tex_init(&(info->tex_no), splited);
		ret |= south_tex_init(&(info->tex_so), splited);
		ret |= east_tex_init(&(info->tex_ea), splited);
		ret |= west_tex_init(&(info->tex_we), splited);
		free_all((void **)splited);
		free(splited);
		i++;
	}
	ret |= texture_init_check(*info);
	return (ret);
}
