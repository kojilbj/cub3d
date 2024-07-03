/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:09:54 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/20 15:09:57 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
tex->pixeis -> two-dimensional array for texture pixel
*/
static void	init_tex_pixels(t_info *info)
{
	int i;

	info->tex_pixels = ft_calloc(WIN_HEIGHT + 1, sizeof(*(info->tex_pixels)));
	//write manege error

	i = 0;
	while (i < WIN_HEIGHT)
	{
		info->tex_pixels[i] = ft_calloc(WIN_WIDTH + 1, sizeof(*(info->tex_pixels)));
		i++;
	}
}

static void	render_frame(t_vars *vars)
{

	
	int		x;
	int		y;
	int		floor_color = 0xAAAAAA; // Gray color for the floor
	int		ceiling_color = 0xDDDDFF; // Light blue color for the ceiling
	t_img	img;

	img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bites_per_pixel, &img.size_line, &img.endian);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
    	while (x < WIN_WIDTH)
    	{
        	// img.addr[y * WIN_WIDTH + x] = vars->info.tex_pixels[y][x];
			if (vars->info.tex_pixels[y][x] > 0)
        		img.addr[y * WIN_WIDTH + x] = vars->info.tex_pixels[y][x]; // Existing texture mapping
			else if (y < WIN_HEIGHT / 2)
				img.addr[y * WIN_WIDTH + x] = ceiling_color; // Set ceiling color
			else if (y > WIN_HEIGHT - 1)
				img.addr[y * WIN_WIDTH + x] = floor_color; // Set floor color
			x++;
    	}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}

void	rendering(t_vars *vars)
{
	init_tex_pixels(&(vars->info));
	raycasting(&(vars->info));
	render_frame(vars);
}

int	render(t_vars *vars)
{
	rendering(vars);
	return (0);
}
