#include "./cub3d.h"

int	x_open(char *path, int oflag)
{
	int	fd;

	fd = open(path, oflag);
	if (fd < 0)
	{
		perror("open");
		return (fd);
	}
	return (fd);
}