/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:48:49 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 11:18:45 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	north_tex_init(char **tex_no, char **sp)
{
	if (sp == NULL)
		return (1);
	if (perfectly_match(sp[0], "NO"))
	{
		if (*tex_no != NULL)
		{
			put_error("north texture is duplicated.\n");
			return (1);
		}
		if (sp[1] == NULL)
			return (1);
		*tex_no = ft_strdup(sp[1]);
	}
	return (0);
}

int	south_tex_init(char **tex_so, char **sp)
{
	if (sp == NULL)
		return (1);
	if (perfectly_match(sp[0], "SO"))
	{
		if (*tex_so != NULL)
		{
			put_error("south texture is duplicated.\n");
			return (1);
		}
		if (sp[1] == NULL)
			return (1);
		*tex_so = ft_strdup(sp[1]);
	}
	return (0);
}

int	east_tex_init(char **tex_ea, char **sp)
{
	if (sp == NULL)
		return (1);
	if (perfectly_match(sp[0], "EA"))
	{
		if (*tex_ea != NULL)
		{
			put_error("east texture is duplicated.\n");
			return (1);
		}
		if (sp[1] == NULL)
			return (1);
		*tex_ea = ft_strdup(sp[1]);
	}
	return (0);
}

int	west_tex_init(char **tex_we, char **sp)
{
	if (sp == NULL)
		return (1);
	if (perfectly_match(sp[0], "WE"))
	{
		if (*tex_we != NULL)
		{
			put_error("west texture is duplicated.\n");
			return (1);
		}
		if (sp[1] == NULL)
			return (1);
		*tex_we = ft_strdup(sp[1]);
	}
	return (0);
}
