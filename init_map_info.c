/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:53 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 11:10:07 by watanabekoj      ###   ########.fr       */
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

	ft_bzero(info, sizeof(t_info));
	filedata = file_to_string(path);
	if (filedata == NULL)
		return (1);
	splited = ft_split(filedata, '\n');
	if (texture_init(info, splited) != 0)
		return (1);
	if (color_init(info, splited) != 0)
		return (2);
	if (player_init(info, splited) != 0)
		return (3);
	if (map_init(info, splited) != 0)
		return (4);
	free_all((void **)splited);
	free(splited);
	return (0);
}
