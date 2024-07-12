/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:09:54 by hosonu            #+#    #+#             */
/*   Updated: 2024/07/09 14:11:31 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
tex->pixeis -> two-dimensional array for texture pixel
*/
static void	free_tex_pixels(t_info *info, size_t i)
{
	while (i > 0)
	{
		i--;
		free(info->tex_pixels[i]);
	}
	free(info->tex_pixels);
}

static bool	init_tex_pixels(t_info *info)
{
	size_t	i;

	info->tex_pixels = ft_calloc(WIN_HEIGHT + 1, sizeof(int *));
	if (info->tex_pixels == NULL)
		return (false);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		info->tex_pixels[i] = ft_calloc(WIN_WIDTH, sizeof(int));
		if (info->tex_pixels[i] == NULL)
		{
			free_tex_pixels(info, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	set_pixel_color(t_vars *vars, t_img *img, int x, int y)
{
	if (vars->info.tex_pixels[y][x] > 0)
		img->addr[y * (img->size_line / 4) + x]
			= vars->info.tex_pixels[y][x];
	else if (y < WIN_HEIGHT / 2)
		img->addr[(y * (img->size_line / 4)) + x]
			= vars->info.ceiling_rgb;
	else if (y < (WIN_HEIGHT - 1))
		img->addr[(y * (img->size_line / 4)) + x] = vars->info.floor_rgb;
}

static void	render_frame(t_vars *vars)
{
	int		x;
	int		y;
	t_img	img;

	img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bites_per_pixel,
			&img.size_line, &img.endian);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_pixel_color(vars, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
	double_free(vars->info.tex_pixels);
}

void	rendering(t_vars *vars)
{
	if (init_tex_pixels(&(vars->info)) == false)
	{
		double_free(vars->info.tex_list);
		cleanup_on_alloc_failure(vars);
	}
	raycasting(&(vars->info));
	render_frame(vars);
}
