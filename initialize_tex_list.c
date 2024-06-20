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

sattic void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bites_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
}

static void	load_texture(t_info *info, t_img *img, const char *path)
{
	init_img(image);
    image->img = mlx_xpm_file_to_image(/*mlx*/, path, TEX_SIZE, TEX_SIZE);
    if (image->img == NULL)
        //manage error 
    image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
}

static int get_img_from_xpm(t_info *info, const char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	load_texture(info, &tmp, path);
	buffer = ft_calloc(1, sizeof(int) * TEX_SIZE * TEX_SIZE);
	y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			buffer[y * TEX_SIZE + x] = tmp.addr[y * TEX_SIZE];
			x++;
		}
		y++;
	}
	//mlx_destroy_image();
	return (buffer);
}
	
void	initialize_tex_list(t_info *info)
{
	info->tex_list = ft_calloc(5, sizeof(int *));
	//manage error

	info->tex_list[NORTH] =  get_img_from_xpm(info, info->tex_no);
	info->tex_list[SOUTH] = get_img_from_xpm(info, info->tex_so);
	info->tex_list[EAST] = get_img_from_xpm(info, info->tex_ea);
	info->tex_list[WEST] = get_img_from_xpm(info, info->tex_we);
}
