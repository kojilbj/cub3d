#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_info	info;

	info_init(&info, av[1]);
	ray_direct(info);
}
