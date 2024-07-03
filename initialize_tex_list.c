/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_tex_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:56:25 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/20 16:56:28 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**********************************/
/*			TEXTURE_LIST		  */
/**********************************/

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bites_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
}

static void	load_texture(t_vars *vars, t_img *image, char *path)
{
	int	width;
	int	height;

	width = TEX_SIZE;
	height = TEX_SIZE;
	init_img(image);
    image->img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
    if (image->img == NULL)
    {
		printf("fuck off\n");
		exit(1);
	}
    image->addr = (int *)mlx_get_data_addr(image->img, &image->bites_per_pixel, &image->size_line, &image->endian);
}

static int *get_img_from_xpm(t_vars *vars, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	load_texture(vars, &tmp, path);
	buffer = ft_calloc(1, sizeof(int) * TEX_SIZE * TEX_SIZE);
	y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			buffer[y * TEX_SIZE + x] = tmp.addr[y * TEX_SIZE + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->mlx, tmp.img);
	return (buffer);
}
	
void	initialize_tex_list(t_vars *vars)
{
	vars->info.tex_list = ft_calloc(5, sizeof(int *));
	//manage error

	vars->info.tex_list[NORTH] =  get_img_from_xpm(vars, vars->info.tex_no);
	vars->info.tex_list[SOUTH] = get_img_from_xpm(vars, vars->info.tex_so);
	vars->info.tex_list[EAST] = get_img_from_xpm(vars, vars->info.tex_ea);
	vars->info.tex_list[WEST] = get_img_from_xpm(vars, vars->info.tex_we);
}


