/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:06:17 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/03 17:24:51 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_map(t_node **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x].type != '\0')
		{
			printf("%c", map[y][x].type);
			x++;
		}
		printf("\n");
		y++;
	}
}

int	key_hook_handler(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free(vars->win);
		free_info(vars->info);
		// sleep(10);//to monitor momory-leaks
		exit(EXIT_SUCCESS);
	}
	rotate_player(&(vars->info.player), keycode);
	move_player(vars, keycode);
	display_map(vars->info.map);
	return (0);
}

int	terminate_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_info(vars->info);
	// sleep(10);//to monitor momory-leaks
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
	{
		put_error("invalid argument(s).\n");
		return (1);
	}
	if (file_name_validate(av[1]) != 0)
	{
		put_error("invalid map-file name.\n");
		return (1);
	}
	if (init_map_info(&(vars.info), av[1]) != 0)
	{
		free_info(vars.info);
		return (1);
	}
	//printf("%d\n", vars.info.ceiling_rgb);
	//validate(vars.info);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_hook(vars.win, 2, 1L << 0, key_hook_handler, &vars);
	mlx_hook(vars.win, 17, 1 << 17, terminate_handler, &vars);
	mlx_loop(vars.mlx);
}
