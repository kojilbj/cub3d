/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:53 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/17 15:33:44 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	init_map_info(t_info *info, char *path)
{
	char	*filedata;
	char	**splited;
	int		ret;

	ret = 0;
	ft_bzero(info, sizeof(t_info));
	info->ceiling_rgb = -1;
	info->floor_rgb = -1;
	filedata = file_to_string(path);
	if (filedata == NULL)
		return (1);
	splited = ft_split(filedata, '\n');
	free(filedata);
	if (texture_init(info, splited) != 0)
		ret = 1;
	if (ret == 0 && color_init(info, splited) != 0)
		ret = 2;
	if (ret == 0 && player_init(info, splited) != 0)
		ret = 3;
	if (ret == 0 && map_init(info, splited) != 0)
		ret = 4;
	free_all((void **)splited);
	free(splited);
	return (ret);
}
