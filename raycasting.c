/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:56 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/19 15:50:00 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
initialize rays(struct ray)
- x_cam -> where is camera(-1 <= x <= 1)
- x/y_dir -> direction of the ray(vector of ray)
- x/y_map -> current position of ray on map
- 
*/

void	init_ray_info()
{
	ray->x_cam = 2*x / (double)WINT_WIDTH - 1;

}



void	raycasting()//get_var_of_player_info
{

}