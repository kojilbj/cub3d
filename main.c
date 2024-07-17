/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:06:17 by kojwatan          #+#    #+#             */
/*   Updated: 2024/07/17 16:14:44 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	display_map(t_node **map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (map[y] != NULL)
// 	{
// 		x = 0;
// 		while (map[y][x].type != '\0')
// 		{
// 			printf("%c", map[y][x].type);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
int	key_hook_handler(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free_info(vars->info);
		double_free(vars->info.tex_list);
		exit(EXIT_SUCCESS);
	}
	if (keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT)
		rotate_camera(vars, keycode);
	move_player(vars, keycode);
	return (0);
}

int	terminate_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_info(vars->info);
	double_free(vars->info.tex_list);
	exit(EXIT_SUCCESS);
	return (0);
}

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		perror("mlx_init");
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (vars->win == NULL)
	{
		perror("mlx_new_window");
		mlx_destroy_display(vars->mlx);
		return (1);
	}
	return (0);
}

int	init_vars(t_vars *vars, char *av)
{
	if (init_map_info(&(vars->info), av) != 0)
	{
		free_info(vars->info);
		return (1);
	}
	if (init_mlx(vars) != 0)
	{
		free_info(vars->info);
		return (1);
	}
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
	if (init_vars(&vars, av[1]) != 0)
		return (1);
	initialize_tex_list(&vars);
	rendering(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook_handler, &vars);
	mlx_hook(vars.win, 9, 1 << 21, rendering, &vars);
	mlx_hook(vars.win, 17, 1 << 17, terminate_handler, &vars);
	mlx_loop(vars.mlx);
}
