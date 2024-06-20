/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:06:17 by kojwatan          #+#    #+#             */
/*   Updated: 2024/06/20 15:06:18 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_handler(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	rotate_player(&(vars->info.player), keycode);
	move_player(vars, keycode);
	return (0);
}

int	terminate_handler(t_vars *vars)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	info_init(&(vars.info), av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_hook(vars.win, 2, 1L << 0, key_hook_handler, &vars);
	mlx_hook(vars.win, 17, 1 << 17, terminate_handler, &vars);
	mlx_loop(vars.mlx);
	//ray_direct(info);
}
