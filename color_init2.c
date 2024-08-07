/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:58:07 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/17 15:39:31 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

bool	is_valid_format(char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && str[i] != ' ' && ft_isdigit(str[i]) != 1)
		{
			put_error("color format.\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int	color_range_check(char *str)
{
	char	**sp;
	int		num;
	int		ret;
	size_t	i;

	sp = ft_split(str, ',');
	i = 0;
	ret = 0;
	while (sp[i] != NULL)
	{
		num = ft_atoi(sp[i]);
		if (!(0 <= num && num < 256))
			ret = 1;
		i++;
	}
	free_all((void **)sp);
	free(sp);
	if (i != 3)
	{
		put_error("Invalid color format.\n");
		return (1);
	}
	return (ret);
}

int	convert_str_to_rgb(char *str)
{
	int		i;
	int		rgb;
	char	**sp;

	rgb = 0;
	i = 0;
	sp = ft_split(str, ',');
	while (sp[i] != NULL)
	{
		rgb = rgb << 8;
		rgb = rgb + ft_atoi(sp[i]);
		i++;
	}
	free_all((void **)sp);
	free(sp);
	return (rgb);
}
