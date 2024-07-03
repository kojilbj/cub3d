/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:16 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 17:09:18 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	free_all(void **data)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
}

void	free_info(t_info info)
{
	free(info.tex_no);
	free(info.tex_so);
	free(info.tex_we);
	free(info.tex_ea);
	free_all((void **)info.map);
	free(info.map);
}
