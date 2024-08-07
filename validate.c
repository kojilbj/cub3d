/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:05 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/24 16:10:53 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error(char *errmsg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
}

//the third arg of ft_strncmp for the purpose of validating hidden file
//invalid:".cub"  valid:".map.cub"
int	file_name_validate(char *arg)
{
	char	*ptr;

	if (ft_strlen(arg) < 5)
		return (1);
	ptr = ft_strrchr(arg, '.');
	if (ptr == NULL || ft_strncmp(ptr, ".cub\0", 5))
		return (1);
	return (0);
}
