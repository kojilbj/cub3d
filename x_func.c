/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:49:40 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/02 22:49:41 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	x_open(char *path, int oflag)
{
	int	fd;

	fd = open(path, oflag);
	if (fd < 0)
	{
		perror("open");
		return (fd);
	}
	return (fd);
}

void	double_free(int **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	cleanup_on_alloc_failure(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_info(vars->info);
	exit(EXIT_FAILURE);
}
