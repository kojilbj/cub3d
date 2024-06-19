#include "cub3d.h"

void	ray_direct(t_info info)
{
	t_player	player;
	size_t	x;
	double	current_cam_x;
	double	ray_dir_x;
	double	ray_dir_y;

	player = info.player;
	x = 0;
	while (x < WIN_WIDTH)
	{
		current_cam_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = player.dir_x + player.pos_x * current_cam_x;
		ray_dir_y = player.dir_y  + player.pos_y * current_cam_x;
		printf("ray_dir_x %f\n", ray_dir_x);
		printf("ray_dir_y %f\n", ray_dir_y);
		printf("\n");
		x++;
	}

}
