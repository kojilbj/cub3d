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

void	init_tex_pixels(t_info *info)
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

void	render_frame(t_info *info)
{
	/*
	１. 指定された幅と高さの画像を作成
	２．ウィンドウ全体のピクセルを走査
	３．各ピクセルの色を”レイキャスティング”の結果の基づいて設定
	４．作成された画像をウィンドに描画
	５．使用した画像リソースの解放
	*/
}

void	rendering(t_info *info)
{
	init_tex_pixels(info);
	raycasting(info);
	render_frame(info);
}


